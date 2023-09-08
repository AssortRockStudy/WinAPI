#pragma once

class MyPathMgr
{
private:
	static wchar_t m_szContent[255];

public:
	static void init();
	static const wchar_t* GetContentPath() { return m_szContent; }

public:
	MyPathMgr();
	~MyPathMgr();
};

