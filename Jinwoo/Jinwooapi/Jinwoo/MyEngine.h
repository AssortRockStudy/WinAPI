#pragma once

class MyLevel;

class MyEngine
{
	SINGLETON(MyEngine);

private:
	HWND		m_hWnd;
	POINT		m_ptResolution;
	HDC			m_DC;

	HDC			m_SubDC;
	HBITMAP		m_SubBitMap;

	MyLevel*	m_Level;

public:
	HWND GetMainhWnd() { return m_hWnd; }
	POINT GetMainResolution() { return m_ptResolution; }
	HDC GetMainDC() { return m_DC; }

public:
	void init(HWND _hWnd, POINT _ptResolution);
	void tick();
};

