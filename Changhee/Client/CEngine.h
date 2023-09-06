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

	// 자주 사용할 pen, brush
	HPEN	m_arrPen[(UINT)PEN_TYPE::END];
	HBRUSH	m_arrBrush[(UINT)BRUSH_TYPE::END];

private:
	void CreatePenBrush();

public:
	HPEN GetPEN(PEN_TYPE _ePenType) { return m_arrPen[(UINT)_ePenType]; }
	HBRUSH GetBRUSH(BRUSH_TYPE _eBrushType) { return m_arrBrush[(UINT)_eBrushType]; }

public:
	void init(HWND _hWnd, POINT _ptResolution);
	void tick();

};

