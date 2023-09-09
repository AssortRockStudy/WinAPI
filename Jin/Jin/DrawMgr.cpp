#include "pch.h"
#include "DrawMgr.h"

DrawMgr::DrawMgr() {}

DrawMgr::~DrawMgr() 
{
	//for (int i = 0; i < pens.size(); ++i)
	//{
	//	DeleteObject(pens[i]);
	//	DeleteObject(brushes[i]);
	//}

}

void DrawMgr::init()
{
	HPEN hBlackPen = CreatePen(PS_SOLID, 1, RGB(0,0,0));
	pens.push_back(&hBlackPen);
	HPEN hRedPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	pens.push_back(&hRedPen);
	HPEN hGreenPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	pens.push_back(&hGreenPen);
	HPEN hBluePen = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
	pens.push_back(&hBluePen);
	HPEN hWhitePen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
	pens.push_back(&hWhitePen);

	HBRUSH hBlackBrush = CreateSolidBrush(RGB(0, 0, 0));
	brushes.push_back(&hBlackBrush);
	HBRUSH hRedBrush = CreateSolidBrush(RGB(255, 0, 0));
	brushes.push_back(&hRedBrush);
	HBRUSH hGreenBrush = CreateSolidBrush(RGB(0, 255, 0));
	brushes.push_back(&hGreenBrush);
	HBRUSH hBlueBrush = CreateSolidBrush(RGB(0, 0, 255));
	brushes.push_back(&hBlueBrush);
	HBRUSH hWhiteBrush = CreateSolidBrush(RGB(255, 255, 255));
	brushes.push_back(&hWhiteBrush);

}

void DrawMgr::tick()
{

}
