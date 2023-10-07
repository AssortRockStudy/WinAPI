#include "pch.h"
#include "Anim.h"
#include "Animator.h"
#include "CObj.h"
#include "Camera.h"
#include "CTexture.h"
#include "CTimeMgr.h"
#include "LogMgr.h"
#include "CAssetMgr.h"

void Anim::finalTick(){
	if (finished)
		return;
	float dt = CTimeMgr::GetInst()->getDeltaTime();
	accTime += dt;

	if (vecFrm[mCurFrame].duration < accTime) {
		accTime = 0.f;
		if (vecFrm.size() - 1 <= mCurFrame)
			finished = true;
		else
			++mCurFrame;
	}
}

void Anim::render(HDC _dc){
	const Frame& frm = vecFrm[mCurFrame];

	CObj* pOwnerObject = mAnimator->getOwner();
	Vec2 vRenderPos = pOwnerObject->getRenderPos();

	TransparentBlt(_dc, int(vRenderPos.x - (frm.cutSize.x / 2.f) + frm.offset.x)
		, int(vRenderPos.y - (frm.cutSize.y / 2.f) + frm.offset.y)
		, int(frm.cutSize.x), int(frm.cutSize.y)
		, mAtlas->getDc()
		, int(frm.leftTop.x), int(frm.leftTop.y)
		, int(frm.cutSize.x), int(frm.cutSize.y)
		, RGB(255, 0, 255));
}

void Anim::create(const wstring& _name, CTexture* _atlas, Vec2 _lTop, Vec2 _cutSize, Vec2 _offset, float _duration, int _maxFrm){
	setName(_name);
	mAtlas = _atlas;

	vecFrm.reserve(_maxFrm);

	for (size_t i = 0; i < _maxFrm; ++i){
		Frame frm = {};
		frm.leftTop = _lTop + Vec2(_cutSize.x * i, 0.f);
		frm.cutSize = _cutSize;
		frm.offset = _offset;
		frm.duration = _duration;
		vecFrm.push_back(frm);
	}
}

bool Anim::save(const wstring& _path){
	FILE* pFile = nullptr;

	_wfopen_s(&pFile, _path.c_str(), L"wb");

	if (nullptr == pFile){
		LOG(ERR, L"파일 열기 실패");
		return false;
	}

	wstring strName = getName();
	int iLen = 0;
	iLen = strName.length();
	fwrite(&iLen, sizeof(int), 1, pFile);
	fwrite(strName.c_str(), sizeof(wchar_t), strName.length(), pFile);


	bool bExist = mAtlas;
	fwrite(&bExist, sizeof(bool), 1, pFile);

	if (bExist){
		wstring strKey = mAtlas->getKey();
		wstring strRelativePath = mAtlas->getPath();

		int iLen = 0;

		iLen = strKey.length();
		fwrite(&iLen, sizeof(int), 1, pFile);
		fwrite(strKey.c_str(), sizeof(wchar_t), strKey.length(), pFile);

		iLen = strRelativePath.length();
		fwrite(&iLen, sizeof(int), 1, pFile);
		fwrite(strRelativePath.c_str(), sizeof(wchar_t), strRelativePath.length(), pFile);
	}

	size_t frmCount = vecFrm.size();
	fwrite(&frmCount, sizeof(size_t), 1, pFile);
	fwrite(&vecFrm[0], sizeof(Frame), vecFrm.size(), pFile);

	fclose(pFile);
	return true;
}

bool Anim::load(const wstring& _path){
	FILE* pFile = nullptr;

	_wfopen_s(&pFile, _path.c_str(), L"rb");

	if (nullptr == pFile)
	{
		LOG(ERR, L"파일 열기 실패");
		return false;
	}

	wchar_t szName[255] = {};
	int iLen = 0;
	fread(&iLen, sizeof(int), 1, pFile);
	fread(szName, sizeof(wchar_t), iLen, pFile);

	setName(szName);

	bool bExist = 0;
	fread(&bExist, sizeof(bool), 1, pFile);

	if (bExist){
		wchar_t szBuff[255] = {};

		int iLen = 0;

		fread(&iLen, sizeof(int), 1, pFile);
		fread(szBuff, sizeof(wchar_t), iLen, pFile);
		wstring strKey = szBuff;

		wmemset(szBuff, 0, 255);

		fread(&iLen, sizeof(int), 1, pFile);
		fread(szBuff, sizeof(wchar_t), iLen, pFile);
		wstring strRelativePath = szBuff;

		mAtlas = CAssetMgr::GetInst()->LoadTexture(strKey, strRelativePath);
	}

	size_t FrmCount = 0;
	fread(&FrmCount, sizeof(size_t), 1, pFile);
	vecFrm.resize(FrmCount);
	fread(&vecFrm[0], sizeof(Frame), vecFrm.size(), pFile);

	fclose(pFile);
	return true;
}

Anim::Anim():mAnimator(nullptr), mAtlas(nullptr), mCurFrame(0), finished(false), accTime(0.f){}

Anim::~Anim(){}
