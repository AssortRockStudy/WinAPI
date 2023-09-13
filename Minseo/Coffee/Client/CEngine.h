#pragma once

class CLevel;

class CEngine
{
	SINGLETON(CEngine);
private:
	HWND m_hWnd; // ���� ������ �ڵ�
	POINT m_ptResolution; // ������ �ػ�

	HDC		m_DC;

	HBITMAP m_SubBitMap; // CreateCompatibleBitmap()함수의 반환 값을 받아올 멤버
	HDC		m_SubDC; // m_SubBitMap 비트맵을 가리키는 SubDC 멤버


	CLevel* m_Level;

public:
	HWND GetMainWind() { return m_hWnd; }
	HDC GetMainDC() { return m_DC; }
	POINT GetResolution() { return m_ptResolution; }
	
	void init(HWND _hWnd, POINT _ptResolution);
	void tick();


};

