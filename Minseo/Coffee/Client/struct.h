#pragma once

struct Vec2
{
public:
	float x;
	float y;

public:
	float Distance(Vec2 _Other) // 타겟 까지의 거리 구해서 반환
	{
		return sqrtf(powf(x - _Other.x, 2) + powf(y - _Other.y, 2)); // 타겟과 미사일의 x y 값 차이를 밑변 높이로 보고 피타고라스 정리
	}

	float Length() // 빗변 길이
	{
		return sqrtf(x * x + y * y); // 피타고라스 정리
	}

	Vec2& Normalize() // 벡터 정규화(길이를 1로 만들어서 이리저리 늘릴 수 있도록 만들어 줌)
	{
		float f = Length(); // f에 빗변의 길이를 받아옴
		x /= f; // 빗변의 길이만큼 x y 값을 나누면
		y /= f;

		return *this; // 정규화 된 벡터가 됨
	}
		

public: // 연산자 오버로딩
	Vec2 operator + (Vec2 _Other)
	{
		return Vec2(x + _Other.x, y + _Other.y);
	}
	void operator += (Vec2 _Other)
	{
		x += _Other.x;
		y += _Other.y;
	}
	Vec2 operator + (float _f)
	{
		return Vec2(x + _f, y + _f);
	}
	Vec2 operator += (float _f)
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
	Vec2 operator * (Vec2 _Other)
	{
		return Vec2(x * _Other.x, y * _Other.y);
	}
	Vec2 operator * (float _f)
	{
		return Vec2(x * _f, y * _f);
	}
	void operator *= (float _f)
	{
		x *= _f;
		y *= _f;
	}
	Vec2 operator / (Vec2 _Other)
	{
		return Vec2(x / _Other.x, y / _Other.y);
	}
	Vec2 operator / (float _f)
	{
		return Vec2(x / _f, y / _f);
	}
	void operator /= (float _f)
	{
		x /= _f;
		y /= _f;
	}

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

struct FMonInfo
{
	wchar_t szName[50];
	float HP;
	float MP;
	float Att;
	float Int;
	float Speed;
};

struct FKeyData
{
	KEY			eKey;
	KEY_STATE	eState;
	bool		bPressed;

};