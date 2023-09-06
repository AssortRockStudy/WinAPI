#include "pch.h"
#include "CTimeMgr.h"

CTimeMgr::CTimeMgr()
	: m_Frequency{}
	, m_PrevCount{}
	, m_CurCount{}
	, m_DeltaTime(0.f)
{
}

CTimeMgr::~CTimeMgr()
{
}

void CTimeMgr::init()
{
	// ÃÊ´ç ºóµµ¼ö
	QueryPerformanceFrequency(&m_Frequency);
	QueryPerformanceCounter(&m_PrevCount);
}

void CTimeMgr::tick()
{
	QueryPerformanceCounter(&m_CurCount);


	m_DeltaTime = float(m_CurCount.QuadPart - m_PrevCount.QuadPart)/ float(m_Frequency.QuadPart);


	m_PrevCount = m_CurCount;
}
