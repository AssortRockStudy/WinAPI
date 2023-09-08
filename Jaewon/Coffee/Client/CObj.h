#pragma once
// CObj �߻� Ŭ���� ����
// ��� ����
// 1. mPos : ������Ʈ�� ��ġ ��ǥ�� ����
// 2. mScale : ������Ʈ�� ũ�⸦ ����
// ��� �Լ�
// ���� �����Լ��� ����� ��ӹ޴� Ŭ�������� ���� �����ϵ��� & CObj�� ��ü ������ �ȵǵ���
// tick() : 1������ ���� ������Ʈ �ϴ� �� 
// render() : 1�����Ӹ��� ������Ʈ�� �׸��� �Լ�
// �Ҹ��ڴ� ��ӵ� Ŭ�������� �޶��� �� �־�� �ϱ� ������ �����Լ��� �����д�.
// 

class CObj
{
private:
	Vec2 mPos;
	Vec2 mScale;

public:
	Vec2 getPos() { return mPos; }
	Vec2 getScale() { return mScale; }
	void setPos(Vec2 _pos) { mPos = _pos; }
	void setScale(Vec2 _scale) { mScale = _scale; }

public:
	virtual void tick(float _dt) = 0;
	virtual void render(HDC _dc);

public:
	CObj();
	virtual ~CObj();
};

