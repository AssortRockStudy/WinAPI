#pragma once

#include "Asset.h"


class Sound
	: public Asset
{
private:
	LPDIRECTSOUNDBUFFER		m_pSoundBuffer;
	DSBUFFERDESC			m_tBuffInfo;
	int						m_iVolume;

public:
	virtual bool Load(const wstring& _strFilePath) override;

	// ���� ���
	void Play(bool _bLoop = false);

	// ����������� ���
	void PlayToBGM(bool _bLoop = false);

	// ����
	void Stop(bool _bReset = false);

	// ���� ���� (0 ~ 100)
	void SetVolume(float _fVolume);

	// ���� ��� ��ġ (0 ~ 100)
	void SetPosition(float _fPosition); // 0 ~ 100 ????

private:
	bool LoadWaveSound(const wstring& _strPath);
	int GetDecibel(float _fVolume);

public:
	Sound();
	virtual ~Sound();
};

