#include "pch.h"
#include "TimeMgr.h"

#include "Engine.h"

TimeMgr::TimeMgr()
	: m_Frequency{}
	, m_PrevCount{}
	, m_CurCount{}
	, m_fTime(0.f)
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

	if ((1.f / 60.f) < m_DeltaTime)
		m_DeltaTime = (1.f / 60.f);

	m_fTime += m_DeltaTime;
	if (1.f <= m_fTime)
	{
		wchar_t szText[50] = {};
		swprintf_s(szText, 50, L"DeltaTime : %f, FPS : %d", m_DeltaTime, m_iCall);
		SetWindowText(Engine::GetInst()->GetMainWind(), szText);

		m_iCall = 0;
		m_fTime = 0.f;
	}

	++m_iCall;
}