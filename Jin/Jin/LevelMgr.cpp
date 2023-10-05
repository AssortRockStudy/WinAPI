#include "pch.h"
#include "Engine.h"
#include "LevelMgr.h"
#include "Level.h"
#include "Player.h"
#include "Monster.h"
#include "DrawMgr.h"
#include "Projectile.h"
#include "Guided.h"
#include "Monster.h"


LevelMgr::LevelMgr() {}
LevelMgr::~LevelMgr() {}

void LevelMgr::init()
{
	m_pCurLevel = new Level;

	Player* pPlayer = new Player;

	pPlayer->SetPos(Vec2(500.f, 500.f));
	pPlayer->SetScale(Vec2(50.f, 50.f));

	m_pCurLevel->AddObject(pPlayer);

	Monster* pMonster = nullptr;

	pMonster = new Monster;
	pMonster->SetPos(Vec2(1200.f, 500.f));
	pMonster->SetScale(Vec2(100.f, 100.f));
	m_pCurLevel->AddObject(pMonster);

	pMonster = new Monster;
	pMonster->SetPos(Vec2(1200.f, 200.f));
	pMonster->SetScale(Vec2(100.f, 100.f));
	m_pCurLevel->AddObject(pMonster);

}

void LevelMgr::tick()
{
	m_pCurLevel->tick();
}

void LevelMgr::render(HDC _dc)
{
	POINT ptResolution = Engine::GetInst()->GetResolution();
	HPEN oldPen = (HPEN)SelectObject(_dc, (DrawMgr::GetInst()->pens[WHITE]));
	HPEN oldBrush = (HPEN)SelectObject(_dc, (DrawMgr::GetInst()->brushes[WHITE]));
	Rectangle(_dc, -1, -1, ptResolution.x + 1, ptResolution.y + 1);

	m_pCurLevel->render(_dc);
	BitBlt(Engine::GetInst()->GetMainDC(), 0, 0, ptResolution.x, ptResolution.y, _dc, 0, 0, SRCCOPY);

}
