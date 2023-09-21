#include "pch.h"
#include "struct.h"
#include "CEngine.h"

SelectPen::SelectPen(HDC _dc, PEN_TYPE _type):prevPen(nullptr), curDC(_dc){
	prevPen = (HPEN)SelectObject(curDC, CEngine::GetInst()->getPen(_type));
}

SelectPen::~SelectPen()
{
	SelectObject(curDC, prevPen);
}

SelectBrush::SelectBrush(HDC _dc, HBRUSH _brush) :curDC(_dc), prevBrush(nullptr)
{
	prevBrush = (HBRUSH)SelectObject(curDC, _brush);
}

SelectBrush::~SelectBrush()
{
	SelectObject(curDC, prevBrush);
}
