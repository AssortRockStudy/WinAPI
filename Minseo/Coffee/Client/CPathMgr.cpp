#include "pch.h"
#include "CPathMgr.h"

wchar_t CPathMgr::g_szContent[255] = {};

void CPathMgr::init()
{

	// 실행 파일 경로
	GetCurrentDirectory(255, g_szContent);

	// 화면에 메시지 박스를 표시 가능
	//MessageBox(nullptr, g_szContent, L"Current Directory Check", MB_OK);

	size_t Len = wcslen(g_szContent); // 전체 문자열의 길이를 받아옴

	for (int i = (int)Len - 1; i >= 0; --i) // 문자열 끝부터 처음까지 반복
	{
		if ('\\' == g_szContent[i]) // 만약에 끝부터 문자를 하나하나 가리키는 도중, 배열의 i번째 인덱스가 \ 라면
		{
			g_szContent[i + 1] = '\0'; // 그 다음 문자를 null로 틀어막는다.
			break; // 이후 이전 값들도 바꾸지 않도록 for문 중단
		}
	}

	wcscat_s(g_szContent, 255, L"content\\"); // 인자(문자열(2byte), 문자열의 최대 길이, 이어붙일 문자열) 
	// 이런 식으로 bin에서 content 폴더 까지의 경로를 알 수 있다.
	// 컨텐츠 폴더 안의 리소스 까지의 상대적인 경로를 알아야 한다.
	// 그래야만 뒤에 일정한 값을 붙여서 원하는 파일에 접근이 가능하기 떄문이다.
}
