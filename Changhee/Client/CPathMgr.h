#pragma once
class CPathMgr
{
private:
	static wchar_t g_szContent[255];

public:
	static void init();
	static const wchar_t* GetContentDirectory() { return g_szContent; }

};

