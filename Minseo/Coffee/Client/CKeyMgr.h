#pragma once

// CKeyMgr 사용 이유
// - 키의 상태 값을 관리
//	1.	TAP(입력된 시점)
//	2.	PRESSED(계속 누르는 상태)
//	3.	RELEASED(버튼을 떼는 순간)
//	4.	NONE(버튼을 떼고 있을 때, 아무 것도 아닐 때)
// - 같은 프레임에 동기화 된 키 입력 처리가 가능
//
//
class CKeyMgr
{
	SINGLETON(CKeyMgr);
private:
	vector<FKeyData> m_vecKeyData;
public:
	void init(); // 초기화
	void tick(); // 틱당 수행

	KEY_STATE GetKeyState(KEY _Key)
	{
		return m_vecKeyData[_Key].eState;
	}


};

