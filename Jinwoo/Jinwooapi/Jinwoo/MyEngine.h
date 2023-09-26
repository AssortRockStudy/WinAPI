#pragma once

class MyEngine
{
	SINGLETON(MyEngine);

private:
	HWND		m_hWnd;
	POINT		m_ptResolution;
	HDC			m_DC;

	HDC			m_SubDC;
	HBITMAP		m_SubBitMap;

	bool		m_DebugRender;
	HPEN		m_arrPen[(UINT)PEN_TYPE::END];

public:
	HWND GetMainhWnd() { return m_hWnd; }
	POINT GetMainResolution() { return m_ptResolution; }
	HDC GetMainDC() { return m_DC; }
	HPEN GetPen(PEN_TYPE _Type) { return m_arrPen[(UINT)_Type]; }
	bool DebugRender() { return m_DebugRender; }

private:
	void CreateDefaultGDI();

public:
	void init(HWND _hWnd, POINT _ptResolution);
	void tick();
};

