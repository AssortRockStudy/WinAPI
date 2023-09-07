#pragma once

class CLevel;

class CEngine
{
	SINGLETON(CEngine);

private:
	HWND mHwnd;
	POINT mPtResolution;
	HDC mDc;
	CLevel* mLevel;

public:
	void init(HWND _hwnd, POINT _ptResolution);
	void tick();

};

