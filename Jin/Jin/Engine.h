#pragma once

class Level;

class Engine
{
	SINGLETON(Engine);
private:
	HWND	m_hWnd;
	POINT	m_ptResolution;

	HDC		m_dc;

	Level* m_Level;


public:
	void init(HWND _hWnd, POINT _ptResolution);
	void tick();
};

