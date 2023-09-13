#pragma once
class CPathMgr
{
private:
	static wchar_t g_szContent[255]; // 컨텐츠 경로

public:
	static void init(); // 경로 가져오는 함수
	static const wchar_t* GetContentPath() { return g_szContent; }
};

