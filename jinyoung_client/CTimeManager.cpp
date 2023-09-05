#include "pch.h"
#include "CTimeManager.h"


void CTimeManager::init()
{
	//√ ¥Á ∫Ûµµ
	QueryPerformanceFrequency(&m_CurCount);

	m_DeltaTime= float(m_CurCount.QuadPart - m_PrevCount.QuadPart)/float(m_Frequency.QuadPart);

	m_PrevCount = m_CurCount;

}