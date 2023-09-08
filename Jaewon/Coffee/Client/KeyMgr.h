#pragma once

// Ű�� ���� ���°��� �����ϱ� ���� KeyManager ���
// �̱��� ��ü�� �����ϸ� 
// ���� �����ӿ��� ����ȭ�� Ű�� ó���ϱ� ���� ���
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

