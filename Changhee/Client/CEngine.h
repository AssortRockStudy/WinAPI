#pragma once

class CLevel;

class CEngine
{
	SINGLETON(CEngine);

private:
	HWND		m_hWnd;				// 메인 윈도우 핸들
	HDC			m_dc;
	POINT		m_ptResloution;		// 윈도우 해상도 정보

	CLevel*		m_Level;


public:
	void init(HWND _hWnd, POINT _ptResolution);
	void tick();

};

