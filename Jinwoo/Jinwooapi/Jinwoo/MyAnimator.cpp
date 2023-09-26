#include "pch.h"
#include "MyAnimator.h"

#include "MyPathMgr.h"
#include "MyLogMgr.h"

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

void MyAnimator::CreateAnimation(const wstring& _strName, MyTexture* _Atlas, Vec2 _vLeftTop, Vec2 _vCutSize, Vec2 _vOffset, float _Duration, int _MaxFrame)
{
	MyAnim* pAnim = FindAnim(_strName);

	if (IsValid(pAnim))
	{
		return;
	}

	pAnim = new MyAnim;

	pAnim->m_Animator = this;

	pAnim->Create(_strName, _Atlas, _vLeftTop, _vCutSize, _vOffset, _Duration, _MaxFrame);

	m_mapAnim.insert(make_pair(_strName, pAnim));
}

void MyAnimator::SaveAnimation(const wstring& _strRelativePath)
{
	wstring strFolderPath = MyPathMgr::GetContentPath();
	strFolderPath += _strRelativePath;

	for (const auto& pair : m_mapAnim)
	{
		// pair.first는 애니메이션의 이름(키값)
		wstring strFilePath = strFolderPath + L"\\" + pair.first + L".txt";

		// pair.second는 애니메이션 데이터에 대한 주소값
		// save함수를 호출하여 지정된 경로에 애니메이션을 저장한다
		if (!pair.second->Save(strFilePath))
		{
			LOG(ERR, L"애니메이션 저장 실패");
		}
	}
}

void MyAnimator::LoadAnimation(const wstring& _strRelativePath)
{

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
