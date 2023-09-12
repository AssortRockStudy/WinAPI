#include "pch.h"
#include "CPalette.h"

#include "CEngine.h"

CPalette::CPalette(HDC _dc, PEN_TYPE _ePenType)
	: m_hDC(_dc)
	, m_hDefaultBrush(nullptr)
	, m_hDefaultPen(nullptr)
{
	HPEN hPen = CEngine::GetInst()->GetPEN(_ePenType);
	m_hDefaultPen = (HPEN)SelectObject(_dc, hPen);
}

CPalette::CPalette(HDC _dc, BRUSH_TYPE _eBrushType)
	: m_hDC(_dc)
	, m_hDefaultBrush(nullptr)
	, m_hDefaultPen(nullptr)
{
	HBRUSH hBrush = CEngine::GetInst()->GetBRUSH(_eBrushType);
	m_hDefaultBrush = (HBRUSH)SelectObject(_dc, hBrush);
}

CPalette::~CPalette()
{
	// ´Ù½Ã default·Î ¹Ù²Þ
	SelectObject(m_hDC, m_hDefaultPen);
	SelectObject(m_hDC, m_hDefaultBrush);
}
