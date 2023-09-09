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

public:
	HWND getMainWin() { return mHwnd; }
	POINT getMainResol() { return mPtResolution; }
	HDC getMainDc() { return mDc; }

public:
	void init(HWND _hwnd, POINT _ptResolution);
	void tick();

};

