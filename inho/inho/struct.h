#pragma once

struct Vec2
{
public:
	float x;
	float y;


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
	float Distance(const Vec2 _oth) {
		return sqrtf((x - _oth.x) * (x - _oth.x) + (y - _oth.y) * (y - _oth.y));
	}

	float Length() {
		return sqrtf(x * x + y * y);
	}

	void Normalize() {
		float f = Length();
		x /= f;
		y /= f;
	}

	Vec2 operator + (Vec2 _Other) {
		return Vec2(x + _Other.x, y + _Other.y);
	}
	Vec2 operator - (Vec2 _Other) {
		return Vec2(x - _Other.x, y - _Other.y);
	}

	Vec2 operator *(Vec2 _Other) {
		return Vec2(x * _Other.x, y * _Other.y);
	}

	Vec2 operator /(Vec2 _Other) {
		return Vec2(x / _Other.x, y / _Other.y);
	}
	
};

struct FKeyData {
	KEY eKey;
	KEY_STATE eState;
	bool bPressed;
};

struct FMonInfo {
	wchar_t szName[50];
	float HP;
	float MP;
	float Att;
	float Int;
	float Speed;
};