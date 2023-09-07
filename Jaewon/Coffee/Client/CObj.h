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
	POINT mPos;
	POINT mScale;

public:
	POINT getPos() { return mPos; }
	POINT getScale() { return mScale; }
	void setPos(POINT _pos) { mPos = _pos; }
	void setScale(POINT _scale) { mScale = _scale; }

public:
	virtual void tick() = 0;
	virtual void render(HDC _dc) = 0;

public:
	CObj();
	virtual ~CObj();
};

