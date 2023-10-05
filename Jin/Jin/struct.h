#pragma once

struct Vec2
{
public:
	float x;
	float y;

	float Distance(Vec2 _Other)
	{
		return sqrt(pow(x - _Other.x, 2) + pow(y - _Other.y, 2));
	}

	float Length()
	{
		return sqrt(x * x + y * y);
	}

	void Normalize()
	{
		float f = Length();
		x /= f;
		y /= f;
	}

	Vec2 operator + (Vec2 _Other)
	{
		return Vec2(x + _Other.x, y + _Other.y);
	}
	Vec2 operator - (Vec2 _Other)
	{
		return Vec2(x- _Other.x, y - _Other.y);
	}
	Vec2 operator * (Vec2 _Other)
	{
		return Vec2(x * _Other.x, y * _Other.y);
	}
	Vec2 operator / (Vec2 _Other)
	{
		return Vec2(x / _Other.x, y / _Other.y);
	}

public:
	Vec2()
		: x(0.f)
		, y(0.f)
	{}

	Vec2(float _x, float _y)
		: x(_x), y(_y)
	{}

	Vec2(int _x, int _y)
		: x((float)_x), y((float)_y)
	{}
};

struct FKeyData
{
	KEY eKey;
	KEY_STATE eState;
	bool bPressed;
};

struct FMonInfo
{
	wchar_t szName[50];
	float HP;
	float MP;
	float Att;
	float Int;
	float Speed;
};