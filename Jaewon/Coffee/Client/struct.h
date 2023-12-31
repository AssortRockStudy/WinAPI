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

		assert(f);

		return *this;
	}

	Vec2 operator +(Vec2 _oth){
		return Vec2(x + _oth.x, y + _oth.y);
	}
	Vec2 operator +(float _f) {
		return Vec2(x + _f, y + _f);
	}

	Vec2 operator -(){
		return Vec2(-x, -y);
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
		assert(_oth.x);
		assert(_oth.y);
		return Vec2(x / _oth.x, y / _oth.y);
	}

	Vec2 operator /(float _f) {
		assert(_f);
		return Vec2(x / _f, y / _f);
	}

	void operator /= (float _f)
	{
		assert(_f);
		x /= _f;
		y /= _f;
	}

	bool isZero(){
		if (x == 0.f && y == 0.f)
			return true;
		return false;
	}

public:
	Vec2() : x(0.f), y(0.f){}
	Vec2(float _x, float _y) : x(_x), y(_y) {}
	Vec2(int _x, int _y) : x(float(_x)), y(float(_y)) {}
	Vec2(POINT _x) : x(float(_x.x)), y(float(_x.y)) {}
	Vec2(UINT _x, UINT _y) : x((float)_x), y((float)_y)	{}
};

struct FKeyData {
	KEY key;
	KEYSTATE state;
	bool isPressed;
};

struct FTask {
	TASK_TYPE Type;
	UINT_PTR Param1;
	UINT_PTR Param2;
};

struct SelectPen {
private:
	HPEN prevPen;
	HDC curDC;

public:
	SelectPen(HDC _dc, PEN_TYPE _type);
	~SelectPen();
};

struct SelectBrush {
private:
	HBRUSH prevBrush;
	HDC curDC;

public:
	SelectBrush(HDC _dc, HBRUSH _brush);
	~SelectBrush();
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

struct FLog
{
	LOG_LEVEL Level;
	wstring	  Message;
	float	  AccTime;
};