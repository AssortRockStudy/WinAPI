#include "pch.h"
#include "MyPathMgr.h"

wchar_t MyPathMgr::m_szContent[255] = {};

MyPathMgr::MyPathMgr()
{

}

MyPathMgr::~MyPathMgr()
{

}

void MyPathMgr::init()
{
	// 실행파일 경로
	GetCurrentDirectory(255, m_szContent);

	// 문자열의 길이를 측정하는 함수
	size_t Len = wcslen(m_szContent);

	for (size_t i = Len - 1; i >= 0; --i)
	{
		if ('\\' == m_szContent[i])
		{
			m_szContent[i + 1] = '\0';
			break;
		}
	}

	wcscat_s(m_szContent, 255, L"content\\");
}
