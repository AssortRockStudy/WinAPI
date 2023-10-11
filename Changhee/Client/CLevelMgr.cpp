#include "pch.h"
#include "CLevelMgr.h"

#include "CStartLevel.h"
#include "CEditorLevel.h"
#include "CPlayLevel.h"

CLevelMgr::CLevelMgr()
	: m_pCurLevel(nullptr)
{}


CLevelMgr::~CLevelMgr()
{
	for (UINT i = 0; i < (UINT)LEVEL_TYPE::END; ++i)
	{
		if (nullptr != m_arrLevels[i])
		{
			delete m_arrLevels[i];
		}
	}
}

void CLevelMgr::init()
{
	// ��� ���� ����
	m_arrLevels[(UINT)LEVEL_TYPE::START_LEVEL] = new CStartLevel;
	m_arrLevels[(UINT)LEVEL_TYPE::PLAY_LEVEL] = new CPlayLevel;
	m_arrLevels[(UINT)LEVEL_TYPE::EDITOR_LEVEL] = new CEditorLevel;

	// ���� �ʱ�ȭ
	for (UINT i = 0; i < (UINT)LEVEL_TYPE::END; ++i)
	{
		m_arrLevels[i]->init();
	}

	// Level 
	m_pCurLevel = m_arrLevels[(UINT)LEVEL_TYPE::PLAY_LEVEL];


	m_pCurLevel->begin();

}

void CLevelMgr::tick()
{
	m_pCurLevel->tick();
}

void CLevelMgr::render(HDC _dc)
{
	// Level render
	m_pCurLevel->render(_dc);
}
