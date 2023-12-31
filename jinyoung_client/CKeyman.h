﻿#pragma once

// CKeyman
// ~ 키의 상태값 관리(TAP,PRESSED,RELEASED,NONE)
//프레임당 키의 동기화처리 가능

class CKeyman
{
	SINGLETON(CKeyman);

private:
	vector<FKeyData> m_vecKeyData;

public:

	KEY_STATE GetKeyState(KEY _Key) { return m_vecKeyData[_Key].eState; }

	void init();
	void tick();



};

