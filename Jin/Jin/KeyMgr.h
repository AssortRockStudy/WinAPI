#pragma once
class KeyMgr
{
	SINGLETON(KeyMgr);

private:
	vector<FKeyData> m_vecKeyData;

public:
	KEY_STATE GetKeyState(KEY _key)
	{
		return m_vecKeyData[_key].eState;

	}

	void init();
	void tick();
};

