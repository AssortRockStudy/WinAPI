#pragma once

struct Vec2
{
public:
	float		x;
	float		y;


	Vec2()
		: x(0.f)
		, y(0.f)
	{}

	Vec2(float _x, float _y)
		: x(_x)
		, y(_y)
	{}

	Vec2(int _x, int _y)
		: x((float)_x)
		, y((float)_y)
	{}

	float Length()
	{
		return sqrt(x * x + y * y);
	}

	Vec2& Normalize()
	{
		float fLen = Length();

		assert(fLen != 0.f);
		x /= fLen;
		y /= fLen;

		return *this;
	}

	Vec2 operator * (float _f)
	{
		return Vec2(x * _f, y * _f);
	}


	Vec2 operator - (const Vec2& _Other)
	{
		return Vec2(x - _Other.x, y - _Other.y);
	}

	Vec2 operator + (const Vec2& _Other)
	{
		return Vec2(x + _Other.x, y + _Other.y);
	}
};


struct FKeyData
{
	KEY			eKey;
	KEY_STATE	eState;
	bool		bPressed;
};