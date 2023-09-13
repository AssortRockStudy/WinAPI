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
		return sqrtf(x * x + y * y);
	}

	Vec2& Normalize()
	{
		float fLen = Length();

		assert(fLen != 0.f);
		x /= fLen;
		y /= fLen;

		return *this;
	}

	Vec2 Rotate(float _fTheta)
	{
		Vec2 tmp;

		tmp.x = x * cosf(_fTheta) - y * sinf(_fTheta);
		tmp.y = x * sinf(_fTheta) + y * cosf(_fTheta);

		return tmp;
	}


	Vec2 operator + (const Vec2& _Other)
	{
		return Vec2(x + _Other.x, y + _Other.y);
	}

	Vec2 operator - (const Vec2& _Other)
	{
		return Vec2(x - _Other.x, y - _Other.y);
	}

	Vec2 operator * (const Vec2& _Other)
	{
		return Vec2(x * _Other.x, y * _Other.y);
	}

	Vec2 operator / (const Vec2& _Other)
	{
		assert(_Other.x != 0 && _Other.y != 0);
		return Vec2(x / _Other.x, y / _Other.y);
	}

	Vec2 operator * (float _f)
	{
		return Vec2(x * _f, y * _f);
	}

	Vec2 operator / (float _f)
	{
		assert(_f != 0);
		return Vec2(x / _f, y / _f);
	}

};


struct FKeyData
{
	KEY			eKey;
	KEY_STATE	eState;
	bool		bPressed;
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

struct FTask
{
	TASK_TYPE Type;
	UINT_PTR Param_1;
	UINT_PTR Param_2;
};