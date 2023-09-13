#include "pch.h"
#include "CTimeMgr.h"
#include "CEngine.h"

void CTimeMgr::init()
{
	// 성능 카운터의 초당 빈도를 측정
	// 시스템 부팅 시 고정됨 (최대 1000만)
	QueryPerformanceFrequency(&m_Frequency); 

	// 현재 흐른 빈도를 이전 카운트에 저장
	QueryPerformanceCounter(&m_PrevCount);

}

void CTimeMgr::tick()
{
	// 현재 카운트(흐른 빈도)에서 이전 카운트를 빼면 Delta Time을 추출할 수 있다.
	QueryPerformanceCounter(&m_CurCount);

	m_DeltaTime = float(m_CurCount.QuadPart - m_PrevCount.QuadPart) / float(m_Frequency.QuadPart); // 델타 타임 구하기

	m_PrevCount = m_CurCount; // 틱마다 잴 수 있도록 이전 카운트에 넣어줌

	++m_iCall;
	m_fTime += m_DeltaTime;
	if (1.f < m_fTime) // 만약 게임 시간 1초가 지난 경우
	{
		wchar_t szText[50] = {};

		swprintf_s(szText, 50, L"DeltaTime: %f, FPS: %d", m_DeltaTime, m_iCall); // 문자열 만들기(1초에 1번씩)

		SetWindowText(CEngine::GetInst()->GetMainWind(), szText); // 윈도우 제목을 바꿈.
		m_iCall;
		
		m_iCall = 0;
		m_fTime = 0.f;
	}
}

CTimeMgr::CTimeMgr()
	: m_Frequency{}
	, m_PrevCount{}
	, m_CurCount{}
{

}

CTimeMgr::~CTimeMgr()
{
}
