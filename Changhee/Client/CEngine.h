#pragma once

class CLevel;

class CEngine
{
	SINGLETON(CEngine);

private:
	HWND		m_hWnd;				// ���� ������ �ڵ�
	HDC			m_dc;
	POINT		m_ptResloution;		// ������ �ػ� ����

	CLevel*		m_Level;


public:
	void init(HWND _hWnd, POINT _ptResolution);
	void tick();

};

