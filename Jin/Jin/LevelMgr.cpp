#include "pch.h"
#include "Engine.h"
#include "LevelMgr.h"
#include "Level.h"
#include "Player.h"
#include "Monster.h"
//#include "DrawMgr.h"
#include "Projectile.h"
#include "Guided.h"
#include "Monster.h"
#include "Camera.h"
#include "CollisionMgr.h"

LevelMgr::LevelMgr() {}
LevelMgr::~LevelMgr()
{
	if (nullptr != m_pCurLevel)
		delete m_pCurLevel;
}

void LevelMgr::init()
{
	m_pCurLevel = new Level;

	Player* pPlayer = new Player;

	pPlayer->SetPos(Vec2(500.f, 500.f));
	pPlayer->SetScale(Vec2(50.f, 50.f));

	m_pCurLevel->AddObject(PLAYER, pPlayer);

	pPlayer = new Player;

	pPlayer->SetPos(Vec2(800.f, 500.f));
	pPlayer->SetScale(Vec2(50.f, 50.f));

	m_pCurLevel->AddObject(PLAYER, pPlayer);

	Monster* pMonster = nullptr;

	pMonster = new Monster;
	pMonster->SetPos(Vec2(900.f, 500.f));
	pMonster->SetScale(Vec2(100.f, 100.f));
	m_pCurLevel->AddObject(MONSTER, pMonster);

	Vec2 vLookAt = Engine::GetInst()->GetResolution();
	vLookAt /= 2.f;
	Camera::GetInst()->SetLookAt(vLookAt);

	CollisionMgr::GetInst()->CheckCollision(MONSTER, PLAYER);
	CollisionMgr::GetInst()->CheckCollision(PLAYER_PJ, MONSTER);

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
	BitBlt(Engine::GetInst()->GetMainDC(), 0, 0, ptResolution.x, ptResolution.y, _dc, 0, 0, SRCCOPY);

}
