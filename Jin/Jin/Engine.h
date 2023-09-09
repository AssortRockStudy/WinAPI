#pragma once

class Level;

class Engine
{
	SINGLETON(Engine);
private:
	HWND	m_hWnd;
	POINT	m_ptResolution;

	HDC		m_DC;
	HDC		m_SubDC;
	HBITMAP m_SubBitMap;
	
	Level*	m_Level;


public:
	HWND GetMainWind() { return m_hWnd; }
	HDC GetMainDC() { return m_DC; }
	POINT GetResolution() { return m_ptResolution; }


public:
	void init(HWND _hWnd, POINT _ptResolution);
	void tick();
};

