#pragma once

class MyLevel;

class MyEngine
{
	SINGLETON(MyEngine);

private:
	HWND		m_hWnd;
	POINT		m_ptResolution;
	HDC			m_DC;

	MyLevel*	m_Level;

public:
	void init(HWND _hWnd, POINT _ptResolution);
	void tick();
};

