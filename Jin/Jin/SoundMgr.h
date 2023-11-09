#pragma once

class Sound;

class SoundMgr
{
	SINGLETON(SoundMgr);
private:
	LPDIRECTSOUND8	m_pSound;	// ���� ���� �Ŵ��� ��ü, ���� ī�� ��Ʈ��
	Sound* m_pBGM;		// ���� �߿��� BGM Sound �� ����Ű�� ������

public:
	int init();
	LPDIRECTSOUND8 GetSoundDevice() { return m_pSound; }
	void RegisterToBGM(Sound* _pSound);
};
