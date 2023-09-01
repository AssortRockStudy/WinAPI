#pragma once


//엔진은 게임프로그램의 관리자.
//디자인패턴(설계의 유형)
//Singleton 패턴 단 하나의 객체를 위해설계됨
//두개이상 만들어지는것을 금지함
class CEngine
{
public:
	int m_a;

	//정적 멤버변수
	//-데이터 영역(생성된 객체안에 포함이 안됨,1개) == 모든객체들이 공유하는 하나의 변수
	//  
	//-멤버변수의 특징(멤버함수에서 접근가능) this 없이도 접근가능
	//- 정적멤버함수에서도 접근가능하다.
	// 문법:클래스안에 있는 선언은 전방선언역할
	// 실제 초기화는 cpp에서 해줘야한다.
private:
	static CEngine* pEngine;


public:

	//정적멤버함수
	//객체가 없어도 됨(객체에 상대적이지않음)
	//this가없음
	static CEngine* GetInst()
	{

		//static 정적변수 은 함수의 호출종료 상관없이 유지되는변수
		//초기화는 한번만된다.
		if (nullptr==pEngine)
		{
			pEngine = new CEngine;
		}
		return pEngine;
	}

	static void Destroy()
	{
		delete pEngine;
		pEngine = nullptr;

	}


private:
	//문법, 기본 복사생성자를 삭제한다
	CEngine(const CEngine& _Origin) = delete;
	//생성자체를 외부에서 못하게 막음
	CEngine();

public:
	~CEngine();


};