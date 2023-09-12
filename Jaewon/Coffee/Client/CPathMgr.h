#pragma once
class CPathMgr
{
private:
	static wchar_t mContentPath[255];

public:
	static void init();
	static const wchar_t* getContentPath() { return mContentPath; }
};

