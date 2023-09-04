#pragma once
#include "pch.h"

class CObj
{
private :
	POINT m_Pos;
	POINT m_Scale;

public :
	POINT GetPos() { return m_Pos; }
	POINT GetScale() { return m_Scale; }

	void SetPos(POINT _Pos) { m_Pos = _Pos; }
	void SetScale(POINT _Pos) { m_Pos = _Pos; }

public:
	// �� �����Ӹ��� ������Ʈ�� ����
	virtual void tick() = 0; //���� �����Լ� ==>�߻�ũ����

	//�� �����Ӹ��� ȭ�鿡 ������Ʈ�� �׸��� �Լ�
	virtual void render(HDC _dc);

public:
	CObj();
	virtual ~CObj() = 0;
};