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

	_wfopen_s(&pFile, _path.c_str(), L"w");

	if (nullptr == pFile){
		LOG(ERR, L"파일 열기 실패");
		return false;
	}


	fwprintf_s(pFile, L"[ANIM_NAME]\n");
	wstring strName = getName();
	fwprintf_s(pFile, strName.c_str());
	fwprintf_s(pFile, L"\n\n");
	
	fwprintf_s(pFile, L"[ATLAS_TEXTURE]\n");
	wstring strKey;
	wstring strRelativePath;

	if (isValid(mAtlas)){
		strKey = mAtlas->getKey();
		strRelativePath = mAtlas->getPath();
	}
	fwprintf_s(pFile, strKey.c_str());
	fwprintf_s(pFile, L"\n");
	fwprintf_s(pFile, strRelativePath.c_str());
	fwprintf_s(pFile, L"\n\n");

	fwprintf_s(pFile, L"[FRAME_COUNT]\n");
	fwprintf_s(pFile, L"%d\n\n", vecFrm.size());

	for (size_t i = 0; i < vecFrm.size(); ++i)
	{
		fwprintf_s(pFile, L"[FRAME_NUM]\n");
		fwprintf_s(pFile, L"%d\n", i);

		fwprintf_s(pFile, L"[LEFT_TOP]\n");
		fwprintf_s(pFile, L"%f %f\n", vecFrm[i].leftTop.x, vecFrm[i].leftTop.y);

		fwprintf_s(pFile, L"[CUT_SIZE]\n");
		fwprintf_s(pFile, L"%f %f\n", vecFrm[i].cutSize.x, vecFrm[i].cutSize.y);

		fwprintf_s(pFile, L"[OFFSET]\n");
		fwprintf_s(pFile, L"%f %f\n", vecFrm[i].offset.x, vecFrm[i].offset.y);

		fwprintf_s(pFile, L"[DURATION]\n");
		fwprintf_s(pFile, L"%f\n\n", vecFrm[i].duration);
	}

	fclose(pFile);
	return true;
}

bool Anim::load(const wstring& _path){
	FILE* pFile = nullptr;

	_wfopen_s(&pFile, _path.c_str(), L"r");

	if (nullptr == pFile)
	{
		LOG(ERR, L"파일 열기 실패");
		return false;
	}
	while (true)
	{
		wchar_t szRead[256] = {};
		if (EOF == fwscanf_s(pFile, L"%s", szRead, 256))
			break;

		if (!wcscmp(szRead, L"[ANIM_NAME]"))
		{
			fwscanf_s(pFile, L"%s", szRead, 256);
			setName(szRead);
		}
		else if (!wcscmp(szRead, L"[ATLAS_TEXTURE]"))
		{
			wstring strKey, strRelativePath;

			fwscanf_s(pFile, L"%s", szRead, 256);
			strKey = szRead;

			fwscanf_s(pFile, L"%s", szRead, 256);
			strRelativePath = szRead;

			mAtlas = CAssetMgr::GetInst()->LoadTexture(strKey, strRelativePath);
		}
		else if (!wcscmp(szRead, L"[FRAME_COUNT]"))
		{
			size_t iFrameCount = 0;
			fwscanf_s(pFile, L"%d", &iFrameCount);
			vecFrm.resize(iFrameCount);

			size_t iCurFrame = 0;
			while (true){
				fwscanf_s(pFile, L"%s", szRead, 256);

				if (!wcscmp(szRead, L"[FRAME_NUM]"))
					fwscanf_s(pFile, L"%d", &iCurFrame);

				else if (!wcscmp(szRead, L"[LEFT_TOP]")){
					fwscanf_s(pFile, L"%f", &vecFrm[iCurFrame].leftTop.x);
					fwscanf_s(pFile, L"%f", &vecFrm[iCurFrame].leftTop.y);
				}

				else if (!wcscmp(szRead, L"[CUT_SIZE]")){
					fwscanf_s(pFile, L"%f", &vecFrm[iCurFrame].cutSize.x);
					fwscanf_s(pFile, L"%f", &vecFrm[iCurFrame].cutSize.y);
				}

				else if (!wcscmp(szRead, L"[OFFSET]")){
					fwscanf_s(pFile, L"%f", &vecFrm[iCurFrame].offset.x);
					fwscanf_s(pFile, L"%f", &vecFrm[iCurFrame].offset.y);
				}
				else if (!wcscmp(szRead, L"[DURATION]")){
					fwscanf_s(pFile, L"%f", &vecFrm[iCurFrame].duration);

					if (iFrameCount - 1 <= iCurFrame)
						break;
				}
			}
		}
	}

	fclose(pFile);
	return true;
 }

Anim::Anim():mAnimator(nullptr), mAtlas(nullptr), mCurFrame(0), finished(false), accTime(0.f){}

Anim::~Anim(){}
