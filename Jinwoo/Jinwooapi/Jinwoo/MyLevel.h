#pragma once

class MyObject;

// ������Ʈ�� �������ִ� ���� ���������� ������ �ϴ� Ŭ����
class MyLevel
{
private:
	// ��� ������Ʈ�� MyObject�� ��ӹޱ� ������ MyObject�� �����͸� ������
	// ���� Ŭ�������� ��� ������ �� �ִ�
	vector<MyObject*> m_vecObject;
	
public:
	void tick();
	void render(HDC _dc);

public:
	MyLevel();
	~MyLevel();
};

