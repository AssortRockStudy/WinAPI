﻿#pragma once

class CLevel;

class CEngine {
    SINGLETON(CEngine);

private:
    HWND  m_hWnd;
    POINT m_ptResolution;

    HDC m_dc;
    HDC m_SubDC;
    HBITMAP m_SubBitMap;

    CLevel* m_Level;

public:
    HWND GetMainWind() { return m_hWnd; }
    HDC GetMainDC() { return m_dc; }
    POINT GetResolution() { return m_ptResolution; }

public:
    void init(HWND _hWnd, POINT _ptResolution);
    void tick();
};