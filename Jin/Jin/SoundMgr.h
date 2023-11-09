#pragma once

class Sound;

class SoundMgr
{
	SINGLETON(SoundMgr);
private:
	LPDIRECTSOUND8	m_pSound;	// 사운드 관련 매니저 객체, 사운드 카드 컨트롤
	Sound* m_pBGM;		// 사운드 중에서 BGM Sound 를 가리키는 포인터

public:
	int init();
	LPDIRECTSOUND8 GetSoundDevice() { return m_pSound; }
	void RegisterToBGM(Sound* _pSound);
};
