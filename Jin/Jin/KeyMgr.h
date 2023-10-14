#pragma once
class KeyMgr
{
	SINGLETON(KeyMgr);

private:
	vector<FKeyData> m_vecKeyData;
	Vec2 m_vMousePos;

public:
	KEY_STATE GetKeyState(KEY _key)
	{
		return m_vecKeyData[_key].eState;

	}
	Vec2 GetMousPos()
	{
		return m_vMousePos;
	}

	void init();
	void tick();
};

