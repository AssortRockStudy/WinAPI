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
	
	Vec2 mPos;
	Vec2 mScale;
	OBJECTTYPE mType;

public:
	Vec2 getPos() { return mPos; }
	Vec2 getScale() { return mScale; }
	OBJECTTYPE getType() { return mType; }

	void setPos(Vec2 _pos) { mPos = _pos; }
	void setScale(Vec2 _scale) { mScale = _scale; }
	void setType(OBJECTTYPE _type) { mType = _type; }

public:
	virtual void tick(float _dt) = 0;
	virtual void render(HDC _dc);

public:
	CObj();
	virtual ~CObj();
};

