#pragma once


class CObj
{
private:
	Vec2	m_Pos;
	Vec2	m_Scale;

public:
	Vec2 GetPos() { return m_Pos; }
	Vec2 GetScale() { return m_Scale; }

	void SetPos(Vec2 _Pos) { m_Pos = _Pos; }
	void SetScale(Vec2 _Scale) { m_Scale = _Scale; }

public:
	// �� ������ ���� ������Ʈ�� �� ��
	virtual void tick(float _DT) = 0; // ���� �����Լ� ==> �߻� Ŭ����

	// �� �����Ӹ��� ȭ�鿡 ������Ʈ�� �׸��� �Լ�
	virtual void render(HDC _dc);

public:
	CObj();
	virtual ~CObj();
};