#include "pch.h"
#include "Animator.h"


Animator::Animator(Obj* _Owner)
	: Component(_Owner)
	, m_CurAnim(nullptr)
	, m_bRepeat(false)
{
}

Animator::~Animator()
{
}

void Animator::finaltick(float _DT)
{
}

void Animator::render(HDC _DC)
{
}


void Animator::Play(const wstring& _strName, bool _bRepeat)
{
}

void Animator::Stop()
{
}

void Animator::CreateAnimation()
{
}


