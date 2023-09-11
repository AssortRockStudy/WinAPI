#include "pch.h"
#include "CPathMgr.h"

wchar_t CPathMgr::mContentPath[255] = {}; // 전방선언 + 초기화

void CPathMgr::init() {
	GetCurrentDirectory(255, mContentPath);

	size_t pathLen = wcslen(mContentPath);

	for (int i = pathLen - 1; i >= 0; --i) {
		if ('\\' == mContentPath[i]) {
			// 현재 있는 폴더 명까지 왔을 경우
			// 끝에 null을 붙여 문자열의 끝을 붙인다.
			mContentPath[i + 1] = '\0';

			break;
		}
	}
	wcscat_s(mContentPath, 255, L"content\\");
}