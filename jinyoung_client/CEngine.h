#pragma once


//������ �������α׷��� ������.
//����������(������ ����)
//Singleton ���� �� �ϳ��� ��ü�� ���ؼ����
//�ΰ��̻� ��������°��� ������
class CEngine
{
public:
	int m_a;

	//���� �������
	//-������ ����(������ ��ü�ȿ� ������ �ȵ�,1��) == ��簴ü���� �����ϴ� �ϳ��� ����
	//  
	//-��������� Ư¡(����Լ����� ���ٰ���) this ���̵� ���ٰ���
	//- ��������Լ������� ���ٰ����ϴ�.
	// ����:Ŭ�����ȿ� �ִ� ������ ���漱����
	// ���� �ʱ�ȭ�� cpp���� ������Ѵ�.
private:
	static CEngine* pEngine;


public:

	//��������Լ�
	//��ü�� ��� ��(��ü�� �������������)
	//this������
	static CEngine* GetInst()
	{

		//static �������� �� �Լ��� ȣ������ ������� �����Ǵº���
		//�ʱ�ȭ�� �ѹ����ȴ�.
		if (nullptr==pEngine)
		{
			pEngine = new CEngine;
		}
		return pEngine;
	}

	static void Destroy()
	{
		delete pEngine;
		pEngine = nullptr;

	}


private:
	//����, �⺻ ��������ڸ� �����Ѵ�
	CEngine(const CEngine& _Origin) = delete;
	//������ü�� �ܺο��� ���ϰ� ����
	CEngine();

public:
	~CEngine();


};