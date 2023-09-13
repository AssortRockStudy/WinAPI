#pragma once
// 오브젝트를 담기 위한 Level 클래스
// 멤버 변수
// mVecObjects
// 오브젝트 포인터로 만든 벡터이기 때문에
// 오브젝트 클래스를 상속받은 모든 객체를 담을 수 있음

class CObj;
class Monster;

class CLevel
{
private:
	vector<CObj*> mVecObjects; 

public:
	void tick();
	void render(HDC _dc);

public:
	void AddObj(CObj* _obj) {
		mVecObjects.push_back(_obj);
	}
	Monster* findCloseMon(Vec2 mPos);

public:
	CLevel();
	~CLevel();
};

