#pragma once

struct Vec2
{
	float x;
	float y;

public:
	Vec2() : x(0.f), y(0.f)
	{

	}

	Vec2(float _x, float _y) : x(_x), y(_y)
	{

	}

	Vec2(int _x, int _y) : x((float)_x), y((float)_y)
	{

	}

public:
	float Distance(Vec2 _Other)
	{
		return sqrtf(powf(x - _Other.x, 2) + powf(y - _Other.y, 2));
	}

	float Length()
	{
		return sqrtf(x * x + y * y);
	}

	Vec2& Normalize()
	{
		float fLen = Length();

		x /= fLen;
		y /= fLen;

		return *this;
	}

public:
	// 구조체 크기가 어차피 8바이트라 레퍼런스를 써도 뭐 특별한 이득이 없다
	// 따라서 그냥 지역변수로 인자를 받아도 무방
	Vec2 operator + (Vec2 _Other)
	{
		return Vec2(x + _Other.x, y + _Other.y);
	}

	Vec2 operator + (float _f)
	{
		return Vec2(x + _f, y + _f);
	}

	void operator += (Vec2 _Other)
	{
		x += _Other.x;
		y += _Other.y;
	}

	void operator += (float _f)
	{
		x += _f;
		y += _f;
	}

	Vec2 operator - (Vec2 _Other)
	{
		return Vec2(x - _Other.x, y - _Other.y);
	}

	Vec2 operator - (float _f)
	{
		return Vec2(x - _f, y - _f);
	}

	void operator -= (Vec2 _Other)
	{
		x -= _Other.x;
		y -= _Other.y;
	}

	void operator -= (float _f)
	{
		x -= _f;
		y -= _f;
	}

	Vec2 operator * (Vec2 _Other)
	{
		return Vec2(x * _Other.x, y * _Other.y);
	}

	Vec2 operator * (float _f)
	{
		return Vec2(x * _f, y * _f);
	}

	void operator *= (Vec2 _Other)
	{
		x *= _Other.x;
		y *= _Other.y;
	}

	void operator *= (float _f)
	{
		x *= _f;
		y *= _f;
	}

	Vec2 operator / (float _Other)
	{
		return Vec2(x / _Other, y / _Other);
	}
};

struct FKeyData
{
	KEY			eKey;
	KEY_STATE	eState;
	bool		bPressed;
};