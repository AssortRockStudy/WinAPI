#include "pch.h"
#include "SoundMgr.h"

#include "Engine.h"
#include "Sound.h"

SoundMgr::SoundMgr()
	: m_pSound(nullptr)
	, m_pBGM(nullptr)
{
}

SoundMgr::~SoundMgr()
{
}

int SoundMgr::init(void)
{
	if (FAILED(DirectSoundCreate8(NULL, &m_pSound, NULL)))
	{
		MessageBox(NULL, L"���� ����̽� ���� ����", L"SYSTEM ERROR", MB_OK);
		return false;
	}

	// ���� �������� ����
	HWND hWnd = Engine::GetInst()->GetMainWind();
	if (FAILED(m_pSound->SetCooperativeLevel(hWnd, DISCL_EXCLUSIVE))) // Flag?? ????
	{
		MessageBox(NULL, L"���� �Ŵ��� �ʱ�ȭ ����", L"SYSTEM ERROR", MB_OK);
		return false;
	}

	return true;
}

void SoundMgr::RegisterToBGM(Sound* _pSound)
{
	if (m_pBGM != nullptr)
		m_pBGM->Stop(true);

	m_pBGM = _pSound;
}