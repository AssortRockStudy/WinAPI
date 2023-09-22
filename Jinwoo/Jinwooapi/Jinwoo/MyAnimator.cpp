#include "pch.h"
#include "MyAnimator.h"

#include "MyAnim.h"

MyAnimator::MyAnimator(MyObject* _Object) : MyComponent(_Object), m_CurAnim(nullptr), m_Repeat(false)
{

}

MyAnimator::~MyAnimator()
{
	for (const auto& pair : m_mapAnim)
	{
		delete pair.second;
	}
}



void MyAnimator::Play(const wstring& _strName, bool _repeat)
{
	m_Repeat = _repeat;

	m_CurAnim = FindAnim(_strName);
}

void MyAnimator::Stop()
{

}

MyAnim* MyAnimator::FindAnim(const wstring& _strName)
{
	map<wstring, MyAnim*>::iterator iter = m_mapAnim.find(_strName);

	if (iter == m_mapAnim.end())
	{
		return nullptr;
	}

	return iter->second;
}

void MyAnimator::CreateAnimation(const wstring& _strName, MyTexture* _Atlas, Vec2 _vLeftTop, Vec2 _vCutSize, float _Duration, int _MaxFrame)
{
	MyAnim* pAnim = FindAnim(_strName);

	if (IsValid(pAnim))
	{
		return;
	}

	pAnim = new MyAnim;

	pAnim->m_Animator = this;

	pAnim->Create(_strName, _Atlas, _vLeftTop, _vCutSize, _Duration, _MaxFrame);

	m_mapAnim.insert(make_pair(_strName, pAnim));
}


void MyAnimator::finaltick(float _DT)
{
	if (IsValid(m_CurAnim))
	{
		if (m_Repeat && m_CurAnim->IsFinish())
		{
			m_CurAnim->Reset();
		}

		m_CurAnim->finaltick();
	}
}

void MyAnimator::render(HDC _dc)
{
	if (IsValid(m_CurAnim))
	{
		m_CurAnim->render(_dc);
	}
}
