#pragma once

// CKeyman
// ~ Ű�� ���°� ����(TAP,PRESSED,RELEASED,NONE)
//�����Ӵ� Ű�� ����ȭó�� ����

class CKeyman
{
	SINGLETON(CKeyman);


public:
	void init();
	void tick();

	KEY_STATE GetKeyState(KEY _Key) { return m_vecKeyData[_Key].eState; }

private:
	vector<FKeyData> m_vecKeyData;


};

