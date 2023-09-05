#include "pch.h"
#include "CTimeManager.h"

// ���� ū �ڷ��� �������� ���� ������ ��Ī�ϴ� DataType ���� ���
union MousePos
{
	struct
	{
		short High;
		short Low;
	};

	UINT value;
};


CTimeManager::CTimeManager()
	: m_Frequency{}
	, m_PrevCount{}
	, m_CurCount{}
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
	QueryPerformanceFrequency(&m_CurCount);

	m_DeltaTime= float(m_CurCount.QuadPart - m_PrevCount.QuadPart)/float(m_Frequency.QuadPart);

	m_PrevCount = m_CurCount;

}