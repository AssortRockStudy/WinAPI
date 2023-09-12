#pragma once

class CPalette
{
private:
	HDC		m_hDC;
	HPEN	m_hDefaultPen;
	HBRUSH	m_hDefaultBrush;

public:
	CPalette(HDC _dc, PEN_TYPE _ePenType);
	CPalette(HDC _dc, BRUSH_TYPE _eBrushType);
	~CPalette();
};

