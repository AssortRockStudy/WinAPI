#include "pch.h"
#include "Animator.h"
#include "Anim.h"
#include "CPathMgr.h"
#include "LogMgr.h"

void Animator::play(const wstring& _strName, bool _bRepeat){
	repeat = _bRepeat;
	curAnim = findAnim(_strName);
}

void Animator::stop(){
}

Anim* Animator::findAnim(const wstring& _name)
{
	map<wstring, Anim*>::iterator iter = mapAnim.find(_name);

	if (iter == mapAnim.end())
		return nullptr;

	return iter->second;
}

void Animator::createAnimation(const wstring& _name, CTexture* _atlus, Vec2 _lTop, Vec2 _cutSize, Vec2 _offset, float _duration, int _maxFrm){
	Anim* pAnim = findAnim(_name);
	if (isValid(pAnim))
		return;

	pAnim = new Anim;
	pAnim->mAnimator = this;
	pAnim->create(_name, _atlus, _lTop, _cutSize, _offset, _duration,  _maxFrm);
	mapAnim.insert(make_pair(_name, pAnim));
}

void Animator::saveAnimation(const wstring& _path)
{
	wstring strFolderPath = CPathMgr::getContentPath();
	strFolderPath += _path;

	for (const auto& pair : mapAnim)
	{
		wstring strFilePath = strFolderPath + L"\\" + pair.first + L".txt";
		if (!pair.second->save(strFilePath))
		{
			LOG(ERR, L"Animation Save ½ÇÆÐ");
		}
	}
}

void Animator::loadAnimation(const wstring& _path)
{
}

void Animator::finalTick(float _dt){
	if (isValid(curAnim))
	{
		if (repeat && curAnim->isFinish())
		{
			curAnim->reset();
		}

		curAnim->finalTick();
	}
}

void Animator::render(HDC _dc){
	if (isValid(curAnim)){
		curAnim->render(_dc);
	}
}

Animator::Animator(CObj* _Owner):Component(_Owner), curAnim(nullptr), repeat(false){}

Animator::~Animator(){
	for (const auto& pair : mapAnim) {
		delete pair.second;
	}
}
