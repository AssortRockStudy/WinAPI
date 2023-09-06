#include "pch.h"
#include "TimeMgr.h"

TimeMgr::TimeMgr()
	: m_Frequency{}
	, m_PrevCount{}
	, m_CurCount{}
{

}

TimeMgr::~TimeMgr()
{
}

void TimeMgr::init()
{
	// √ ¥Á ∫Ûµµ
	QueryPerformanceFrequency(&m_Frequency);

	QueryPerformanceCounter(&m_PrevCount);
}

void TimeMgr::tick()
{
	QueryPerformanceCounter(&m_CurCount);

	m_DeltaTime = float(m_CurCount.QuadPart - m_PrevCount.QuadPart) / float(m_Frequency.QuadPart);

	m_PrevCount = m_CurCount;
}