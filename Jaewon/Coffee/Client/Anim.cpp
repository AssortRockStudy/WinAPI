#include "pch.h"
#include "Anim.h"
#include "Animator.h"
#include "CObj.h"
#include "Camera.h"
#include "CTexture.h"
#include "CTimeMgr.h"
#include "LogMgr.h"

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

	fclose(pFile);
	return true;
}

void Anim::load(const wstring& _path){
}

Anim::Anim():mAnimator(nullptr), mAtlas(nullptr), mCurFrame(0), finished(false), accTime(0.f){}

Anim::~Anim(){}
