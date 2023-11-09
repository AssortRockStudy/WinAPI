#include "pch.h"
#include "Engine.h"
#include "LevelMgr.h"
#include "Level.h"
#include "PlayLevel.h"
#include "StartLevel.h"
#include "EditorLevel.h"
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
	m_arrLevels[(UINT)LEVEL_TYPE::PLAY_LEVEL] = new PlayLevel;
	m_arrLevels[(UINT)LEVEL_TYPE::EDITOR_LEVEL] = new EditorLevel;

	for (UINT i = 0; i < (UINT)LEVEL_TYPE::END; ++i)
	{
		m_arrLevels[i]->init();
	}

	::ChangeLevel(LEVEL_TYPE::PLAY_LEVEL);


}

void LevelMgr::tick()
{
	if(nullptr != m_pCurLevel)
		m_pCurLevel->tick();
}

void LevelMgr::render(HDC _dc)
{
	if (nullptr == m_pCurLevel)
		return;

	POINT ptResolution = Engine::GetInst()->GetResolution();
	Rectangle(_dc, -1, -1, ptResolution.x + 1, ptResolution.y + 1);

	m_pCurLevel->render(_dc);

	LogMgr::GetInst()->tick(_dc);
}


void LevelMgr::ChangeLevel(LEVEL_TYPE _Type)
{
	if (m_pCurLevel == m_arrLevels[(UINT)_Type])
		return;

	if (nullptr != m_pCurLevel)
		m_pCurLevel->exit();

	m_pCurLevel = m_arrLevels[UINT(_Type)];
	m_pCurLevel->enter();
	m_pCurLevel->begin();
}