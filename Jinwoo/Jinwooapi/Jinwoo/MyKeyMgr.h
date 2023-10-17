#pragma once

// 키의 상태값 관리
// TAP(눌렀을 때), PRESSED(누르고 있는 상태), RELEASED(누르던 걸 뗐을 때), NONE
// 같은 프레임에 동기화된 키 입력 처리
class MyKeyMgr
{
	SINGLETON(MyKeyMgr);
private:
	vector<FKeyData>	m_vecKeyData;
	Vec2				m_vMousePos;

public:
	KEY_STATE GetKeyState(KEY _key) { return m_vecKeyData[(int)_key].eState; }
	Vec2 GetMousePos() { return m_vMousePos; }

public:
	void init();
	void tick();
};

