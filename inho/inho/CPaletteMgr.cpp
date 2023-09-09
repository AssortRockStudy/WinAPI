#include "pch.h"

#include "CPaletteMgr.h"
#include "CEngine.h"

CPaletteMgr::CPaletteMgr() {}
CPaletteMgr::~CPaletteMgr() {
    for (auto pen = pens.begin(); pen != pens.end(); ++pen) {
        DeleteObject(pen->second);
    }
    for (auto brush = brushes.begin(); brush != brushes.end(); ++brush) {
        DeleteObject(brush->second);
    }
}

void CPaletteMgr::init(HDC _dc) {
    dc = _dc;
    HPEN blackPen = CreatePen(BS_SOLID, 1, RGB(10, 10, 10));
    AddPen(PenColor::PRED, CreatePen(BS_SOLID, 1, RGB(255, 10, 10)));
    AddPen(PenColor::PBLACK, blackPen);
    AddPen(PenColor::PBLUE, CreatePen(BS_SOLID, 1, RGB(10, 10, 255)));


    HBRUSH blackBrush = CreateSolidBrush(RGB(10, 10, 10));
    AddBrush(BrushColor::BRED, CreateSolidBrush(RGB(255, 10, 10)));
    AddBrush(BrushColor::BBLACK, blackBrush);
    AddBrush(BrushColor::BBLUE, CreateSolidBrush(RGB(10, 10, 255)));

    AddPen(PenColor::PWHITE, (HPEN)SelectObject(dc, blackPen));
    AddBrush(BrushColor::BWHITE, (HBRUSH)SelectObject(dc, blackBrush));


    
}

void CPaletteMgr::AddPen(PenColor en, HPEN pen) { pens[en] = pen; }

bool CPaletteMgr::SelectPen(PenColor en) {
    auto peniter = pens.find(en);
    if (peniter == pens.end()) {
        return false;
    }

    SelectObject(dc, peniter->second);

    return true;
}

void CPaletteMgr::AddBrush(BrushColor en, HBRUSH brush) { brushes[en] = brush; }

bool CPaletteMgr::SelectBrush(BrushColor en) {
    auto brush = brushes.find(en);
    if (brush == brushes.end()) {
        return false;
    }

    SelectObject(dc, brush->second);
    return false;
}
