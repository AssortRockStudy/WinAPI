#include "pch.h"
#include "CPathMgr.h"

wchar_t CPathMgr::mContentPath[255] = {}; // ���漱�� + �ʱ�ȭ

void CPathMgr::init() {
	GetCurrentDirectory(255, mContentPath);

	size_t pathLen = wcslen(mContentPath);

	for (int i = pathLen - 1; i >= 0; --i) {
		if ('\\' == mContentPath[i]) {
			// ���� �ִ� ���� ����� ���� ���
			// ���� null�� �ٿ� ���ڿ��� ���� ���δ�.
			mContentPath[i + 1] = '\0';

			break;
		}
	}
	wcscat_s(mContentPath, 255, L"content\\");
}