#pragma once

// 싱글턴 패턴으로 구현
// 엔진은 단 하나만 생성되어야 함
// 1. 외부에서 객체 생성을 막기위해 생성자를 private
// 2. 정적 멤버 변수로 객체를 선언, cpp에 초기화 (전방 선언과 같음)
// 3. 정적 멤버 함수 GetInst() : 정적 멤버 함수로 외부에 싱글턴 객체의 주소를 주는 함수
// 4. 복사 생성자 꼼수로 객체를 생성할 수 있으므로 막아야 한다.
class CEngine
{
	SINGLETON(CEngine);

private:
	HWND mHwnd;
	POINT mPtResolution;
	HDC MDc;
	
public:
	void init(HWND _hwnd, POINT _ptResolution);
	void tick();

};

