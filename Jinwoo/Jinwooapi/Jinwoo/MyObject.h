#pragma once

// ���ӿ��� �����ϴ� ��� ��ü���� �θ��� ������ �ϴ� Ŭ����
// �갡 ��ü�� ����� �� �ƴϴ� -> �Ҹ��ڸ� �����Լ��� �ؾ���
// ȭ�鿡 ����� �Ǿ���ϱ� ������ render�� �ʿ���
// render�� �ʿ��� ��� -> ��ġ & ũ�� ����
class MyObject
{
private:
	Vec2 m_Pos;
	Vec2 m_Scale;

public:
	Vec2 GetPos() { return m_Pos; }
	Vec2 GetScale() { return m_Scale; }

	void SetPos(Vec2 _Pos) { m_Pos = _Pos; }
	void SetScale(Vec2 _Scale) { m_Scale = _Scale; }

public:
	// ���� ���� �Լ�
	virtual void tick(float _DT) = 0;
	// render�� ���� �������̵� �����ʾƵ� �θ��ʿ��� ����� �� �ֵ��� ������
	virtual void render(HDC _dc);

public:
	MyObject();
	virtual ~MyObject();
};

