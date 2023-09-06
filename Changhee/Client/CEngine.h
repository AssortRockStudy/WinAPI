#pragma once

class CLevel;

class CEngine
{
	SINGLETON(CEngine);

private:
	HWND		m_hWnd;				// ���� ������ �ڵ�
	HDC			m_dc;
	POINT		m_ptResloution;		// ������ �ػ� ����

	CLevel*		m_Level;

	// ���� ����� pen, brush
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

