#include "pch.h"
#include "MyAnimator.h"


MyAnimator::MyAnimator(MyObject* _Object) : MyComponent(_Object), m_CurAnim(nullptr), m_Repeat(false)
{

}

MyAnimator::~MyAnimator()
{
}



void MyAnimator::Play(const wstring& _strName, bool _repeat)
{
}

void MyAnimator::Stop()
{
}

void MyAnimator::CreateAnimation()
{
}

void MyAnimator::finaltick(float _DT)
{
}

void MyAnimator::render(HDC _dc)
{
}
