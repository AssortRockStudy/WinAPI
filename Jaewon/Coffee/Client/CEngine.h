#pragma once

class CLevel;

class CEngine
{
	SINGLETON(CEngine);

private:
	HWND mHwnd;
	POINT mPtResolution;
	HDC mDc;

	HDC subDc;
	HBITMAP subBitMap;
	
	bool debugRender;
	HPEN arrPen[PEN_END];

public:
	HWND getMainWin() { return mHwnd; }
	POINT getMainResol() { return mPtResolution; }
	HDC getMainDc() { return mDc; }
	HPEN getPen(PEN_TYPE _type) { return arrPen[_type]; }
	bool chkDebugRender() { return debugRender; }

private:
	void createGDI();

public:
	void init(HWND _hwnd, POINT _ptResolution);
	void tick();

};

