#include "pch.h"
#include "Engine.h"
#include "LevelMgr.h"
#include "Level.h"
#include "CPlayLevel.h"
#include "CStartLevel.h"
#include "CEditorLevel.h"
#include "Player.h"
#include "Monster.h"
//#include "DrawMgr.h"
#include "Projectile.h"
#include "Guided.h"
#include "Monster.h"
#include "Camera.h"
#include "LogMgr.h"
#include "CollisionMgr.h"
#include "Platform.h"

LevelMgr::LevelMgr() 
	: m_pCurLevel(nullptr)
{}
LevelMgr::~LevelMgr()
{
	for (UINT i = 0; i < (UINT)LEVEL_TYPE::END; ++i)
	{
		if (nullptr != m_arrLevels[i])
			delete m_arrLevels[i];
	}
}

void LevelMgr::init()
{
	m_arrLevels[(UINT)LEVEL_TYPE::START_LEVEL] = new StartLevel;
	m_arrLevels[(UINT)LEVEL_TYPE::PLAY_LEVEL] = new PlayerLevel;
	m_arrLevels[(UINT)LEVEL_TYPE::EDITOR_LEVEL] = new EditorLevel;

	for (UINT i = 0; i < (UINT)LEVEL_TYPE::END; ++i)
	{
		m_arrLevels[i]->init();
	}

	m_pCurLevel = m_arrLevels[(UINT)LEVEL_TYPE::PLAY_LEVEL];


	m_pCurLevel->begin();

}

void LevelMgr::tick()
{
	m_pCurLevel->tick();
}

void LevelMgr::render(HDC _dc)
{
	POINT ptResolution = Engine::GetInst()->GetResolution();
	//HPEN oldPen = (HPEN)SelectObject(_dc, (DrawMgr::GetInst()->pens[WHITE]));
	//HPEN oldBrush = (HPEN)SelectObject(_dc, (DrawMgr::GetInst()->brushes[WHITE]));
	Rectangle(_dc, -1, -1, ptResolution.x + 1, ptResolution.y + 1);

	m_pCurLevel->render(_dc);

	LogMgr::GetInst()->tick(_dc);
	BitBlt(Engine::GetInst()->GetMainDC(), 0, 0, ptResolution.x, ptResolution.y, _dc, 0, 0, SRCCOPY);

}
