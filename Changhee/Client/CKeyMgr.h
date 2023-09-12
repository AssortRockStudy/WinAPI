#pragma once

// TAP, PRESSED, RELEASED, NONE

class CKeyMgr
{
	SINGLETON(CKeyMgr);
private:
	vector<FKeyData>	m_vecKeyData;

public:
	KEY_STATE GetKeyState(KEY _eKey) { return m_vecKeyData[(UINT)_eKey].eState; }


public:
	void init();
	void tick();

};

