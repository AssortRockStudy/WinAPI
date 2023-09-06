#pragma once

class MyObject;

// 오브젝트를 관리해주는 게임 스테이지의 역할을 하는 클래스
class MyLevel
{
private:
	// 모든 오브젝트는 MyObject를 상속받기 때문에 MyObject의 포인터를 받으면
	// 하위 클래스들을 모두 관리할 수 있다
	vector<MyObject*> m_vecObject;
	
public:
	void tick();
	void render(HDC _dc);

public:
	MyLevel();
	~MyLevel();
};

