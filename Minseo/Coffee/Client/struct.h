#pragma once

struct Vec2
{
public:
	float x;
	float y;

public:
	Vec2() // 기본 생성자
		:x(.0f)
		,y(.0f)
	{}
	Vec2(int _x, int _y) // 정수 전용 오버로딩 생성자
		:x((float)_x)
		, y((float)_y)
	{}
	Vec2(float _x, float _y) // 실수 전용 오버로딩 생성자
		:x(_x)
		, y(_y)
	{}
};



struct FKeyData
{
	KEY			eKey;
	KEY_STATE	eState;
	bool		bPressed;

};