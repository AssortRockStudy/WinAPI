#pragma once

class CLevel;

class CEngine {
    SINGLETON(CEngine);

  private:
    HWND  m_hWnd;
    POINT m_ptResolution;

    HDC m_dc;

    CLevel* m_Level;

  public:
    void init(HWND _hWnd, POINT _ptResolution);
    void tick();
};
