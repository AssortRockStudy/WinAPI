#pragma once

// 실수형 좌표 구조체 Vec2 구현
// POINT 형 변수 및 리턴값 다 Vec2로 변경
struct Vec2
{
public:
	float x;
	float y;

public:
	float Distance(Vec2 _oth){
		return sqrtf(powf(x - _oth.x, 2) + powf(y - _oth.y, 2));
	}

	float Length(){
		return sqrtf(x * x + y * y);
	}

	Vec2& Normalize(){
		float f = Length();
		x /= f;
		y /= f;

		return *this;
	}

	Vec2 operator +(Vec2 _oth){
		return Vec2(x + _oth.x, y + _oth.y);
	}
	Vec2 operator +(float _f) {
		return Vec2(x + _f, y + _f);
	}

	Vec2 operator -(Vec2 _oth) {
		return Vec2(x - _oth.x, y - _oth.y);
	}
	Vec2 operator -(float _f) {
		return Vec2(x - _f, y - _f);
	}

	Vec2 operator * (Vec2 _oth)
	{
		return Vec2(x * _oth.x, y * _oth.y);
	}


	Vec2 operator *(float _f) {
		return Vec2(x * _f, y * _f);
	}

	void operator +=(Vec2 _oth){
		x += _oth.x;
		y += _oth.y;
	}
	Vec2 operator +=(float _f){
		x += _f;
		y += _f;
	}

	void operator *=(float _f) {
		x *= _f;
		y *= _f;
	}

	Vec2 operator /(Vec2 _oth) {
		return Vec2(x / _oth.x, y / _oth.y);
	}

	Vec2 operator /(float _f) {
		return Vec2(x / _f, y / _f);
	}

	void operator /= (float _f)
	{
		x /= _f;
		y /= _f;
	}

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