#pragma once
// CObj 추상 클래스 생성
// 멤버 변수
// 1. mPos : 오브젝트의 위치 좌표를 저장
// 2. mScale : 오브젝트의 크기를 저장
// 멤버 함수
// 순수 가상함수로 만들어 상속받는 클래스에서 직접 구현하도록 & CObj는 객체 생성이 안되도록
// tick() : 1프레임 마다 오브젝트 하는 일 
// render() : 1프레임마다 오브젝트를 그리는 함수
// 소멸자는 상속된 클래스마다 달라질 수 있어야 하기 때문에 가상함수로 만들어둔다.
// 

class CObj
{
private:
	POINT mPos;
	POINT mScale;

public:
	POINT getPos() { return mPos; }
	POINT getScale() { return mScale; }

public:
	virtual void tick() = 0;
	virtual void render() = 0;

public:
	CObj();
	virtual ~CObj();
};

