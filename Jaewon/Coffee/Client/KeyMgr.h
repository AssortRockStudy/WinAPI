#pragma once

// 키의 상세한 상태값을 관리하기 위해 KeyManager 사용
// 싱글턴 객체로 생성하며 
// 같은 프레임에서 동기화된 키를 처리하기 위해 사용
class KeyMgr
{
	SINGLETON(KeyMgr);

private:
	vector<FKeyData> vecKeyData;

public:
	KEYSTATE getKeyState(KEY _key) { return vecKeyData[_key].state; }

public:
	void init();
	void tick();
};

