#pragma once

// CKeyman
// ~ Ű�� ���°� ����(TAP,PRESSED,RELEASED,NONE)
//�����Ӵ� Ű�� ����ȭó�� ����

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

