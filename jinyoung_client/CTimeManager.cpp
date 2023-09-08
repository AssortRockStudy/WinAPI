#include "pch.h"
#include "CTimeManager.h"

#include "CEngine.h"

// ���� ū �ڷ��� �������� ���� ������ ��Ī�ϴ� DataType ���� ���
//union MousePos
//{
//	struct
//	{
//		short High;
//		short Low;
//	};
//
//	UINT value;
//};


CTimeManager::CTimeManager()
	: m_Frequency{}
	, m_PrevCount{}
	, m_CurCount{}
	, m_fTime(0.f)
{

}


CTimeManager::~CTimeManager()
{
}

void CTimeManager::init()
{
	// �ʴ� ��
	QueryPerformanceFrequency(&m_Frequency);

	QueryPerformanceCounter(&m_PrevCount);
}



void CTimeManager::tick()
{
	//�ʴ� ��
	QueryPerformanceCounter(&m_CurCount);

	m_DeltaTime= float(m_CurCount.QuadPart - m_PrevCount.QuadPart)/float(m_Frequency.QuadPart);

	m_PrevCount = m_CurCount;

	// �ð� ���� ==> 1�ʸ��� if ���� ����
	m_fTime += m_DeltaTime;
	if (1.f <= m_fTime)
	{
		wchar_t szText[50] = {};
		swprintf_s(szText, 50, L"DeltaTime : %f, FPS : %d", m_DeltaTime, m_iCall);
		SetWindowText(CEngine::GetInst()->GetMainWind(), szText);

		m_iCall = 0;
		m_fTime = 0.f;
	}

	++m_iCall;

}