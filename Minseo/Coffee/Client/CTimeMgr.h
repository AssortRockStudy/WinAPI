#pragma once
#include "pch.h"

class CTimeMgr // delta time을 구하기 위한 타임 메니저
{
	SINGLETON(CTimeMgr);
	LARGE_INTEGER m_Frequency;
	LARGE_INTEGER m_PrevCount;
	LARGE_INTEGER m_CurCount;
	UINT m_iCall;
	float m_fTime;

public:
	float m_DeltaTime; // delta time, 프레임 당 시간

public:

	void init(); // tick호출 전 재기
	void tick();

	float GetDeltaTime() { return m_DeltaTime; }

};

