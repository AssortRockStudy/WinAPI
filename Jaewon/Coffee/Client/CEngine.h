#pragma once

// 싱글턴 패턴으로 구현
// 엔진은 단 하나만 생성되어야 함
// 1. 외부에서 객체 생성을 막기위해 생성자를 private
// 2. 정적 멤버 변수로 객체를 선언, cpp에 초기화 (전방 선언과 같음)
// 3. 정적 멤버 함수 GetInst() : 정적 멤버 함수로 외부에 싱글턴 객체의 주소를 주는 함수
// 4. 복사 생성자 꼼수로 객체를 생성할 수 있으므로 막아야 한다.
class CEngine
{
private:
	static CEngine* g_inst; 

public:

	// 정적 멤버함수는 객체가 없어도 호출될 수 있음
	// this가 없음
	static CEngine* GetInst() {
		if (nullptr == g_inst) {
			g_inst = new CEngine;
		}
		return g_inst;
	}
	void Destroy() {
		delete g_inst;
		g_inst = nullptr;
	}
	
public:
	// 대입 연산자 삭제
	// 2개의 객체가 생성될 일이 없기 때문에 삭제해 주어야 한다.
	CEngine* operator = (const CEngine& _Origin) = delete;

private:
	CEngine();
	// 복사 생성자 삭제
	// 하나만이 존재하므로 복사생성자를 삭제해 주어야 한다.
	CEngine(const CEngine& _Origin) = delete;

public:
	~CEngine();
};

