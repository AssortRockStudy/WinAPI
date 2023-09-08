#pragma once
#include "pch.h"
class CLevel;

//������ �������α׷��� ������.
//����������(������ ����)
//Singleton ���� �� �ϳ��� ��ü�� ���ؼ����
//�ΰ��̻� ��������°��� ������
class CEngine
{

	//���� �������
	//-������ ����(������ ��ü�ȿ� ������ �ȵ�,1��) == ��簴ü���� �����ϴ� �ϳ��� ����
	//  
	//-��������� Ư¡(����Լ����� ���ٰ���) this ���̵� ���ٰ���
	//- ��������Լ������� ���ٰ����ϴ�.
	// ����:Ŭ�����ȿ� �ִ� ������ ���漱����
	// ���� �ʱ�ȭ�� cpp���� ������Ѵ�.
	
	SINGLETON(CEngine);

private:
	HWND	m_hWnd;			// ���� ������ �ڵ�
	POINT	m_ptResolution;	// ������ �ػ�

	HDC		m_dc;

	HBITMAP m_subbitmap;
	HDC		m_subdc;

	CLevel* m_Level;
public:
	void init(HWND _hWnd, POINT _ptResolution);
	void tick();
	//��������Լ�
	//��ü�� ��� ��(��ü�� �������������)
	//this������
	//static CEngine* GetInst()
	//{

	//	//static �������� �� �Լ��� ȣ������ ������� �����Ǵº���
	//	//�ʱ�ȭ�� �ѹ����ȴ�.
	//	if (nullptr==pEngine)
	//	{
	//		pEngine = new CEngine;
	//	}
	//	return pEngine;
	//}

	//static void Destroy()
	//{
	//	delete pEngine;
	//	pEngine = nullptr;
	//}
	
	//���� : �����Ϳ����� �����Ƿ� destroy���ʿ����.
	//���� : runtime ���߿� ���� �� ����. (������ �Ŵ����� �׿����� �� ����)




};