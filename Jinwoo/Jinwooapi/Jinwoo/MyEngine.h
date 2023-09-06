#pragma once

class MyEngine
{
	SINGLETON(MyEngine);

private:
	HWND	m_hWnd;
	POINT	m_ptResolution;
	HDC		m_DC;

public:
	void init(HWND _hWnd, POINT _ptResolution);
	void tick();
};

