#pragma once
class CPathMgr
{
private:
	//���漱���� ���·� �Ǵ°��̱⋚���� cpp���� �ʱ�ȭ�ʿ�!
	static wchar_t g_szContent[255];

public:
	static void init();
	__inline static wchar_t* GetContentDir() { return g_szContent; }
};

