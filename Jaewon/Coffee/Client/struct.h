#pragma once

// 실수형 좌표 구조체 Vec2 구현
// POINT 형 변수 및 리턴값 다 Vec2로 변경
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