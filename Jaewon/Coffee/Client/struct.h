#pragma once

// �Ǽ��� ��ǥ ����ü Vec2 ����
// POINT �� ���� �� ���ϰ� �� Vec2�� ����
struct Vec2
{
public:
	float x;
	float y;

public:
	Vec2() : x(0.f), y(0.f){}
	Vec2(float _x, float _y) : x(_x), y(_y) {}
	Vec2(int _x, int _y) : x(float(_x)), y(float(_y)) {}
};

struct FKeyData {
	KEY key;
	KEYSTATE state;
	bool isPressed;
};