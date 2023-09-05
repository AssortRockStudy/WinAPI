#pragma once
class CTimeManager
{
	SINGLETON(CTimeManager);

private:
	LARGE_INTEGER m_Frequency;
	LARGE_INTEGER m_PrevCount;
	LARGE_INTEGER m_CurCount;

	float m_DeltaTime;

	CTimeManager();

public:
	void init();



};

