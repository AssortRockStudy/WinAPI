#include "pch.h"
#include "MyLevelMgr.h"

#include "MyEngine.h"

#include "MyLevel.h"
#include "MyPlayer.h"
#include "MyMonster.h"

MyLevelMgr::MyLevelMgr()
{

}

MyLevelMgr::~MyLevelMgr()
{

}

void MyLevelMgr::init()
{
	m_pCurLevel = new MyLevel;

	MyPlayer* pPlayer = new MyPlayer;
	MyMonster* pMonster = new MyMonster;

	pPlayer->SetPos(Vec2(500.f, 500.f));
	pPlayer->SetScale(Vec2(50.f, 50.f));

	pMonster->SetPos(Vec2(1000.f, 500.f));
	pMonster->SetScale(Vec2(50.f, 50.f));

	m_pCurLevel->AddObject(pPlayer);
	m_pCurLevel->AddObject(pMonster);
}

void MyLevelMgr::tick()
{
	m_pCurLevel->tick();
}

void MyLevelMgr::render(HDC _dc)
{
	POINT pResolution = MyEngine::GetInst()->GetMainResolution();

	// 화면에 출력되지 않는 SubDC에 새로운 사각형을 그려서 화면을 지운 것처럼 활용
	// 똑같은 크기를 사용할 경우 미세한 테두리가 생기기 때문에 1픽셀씩 더 넓혀서 생성
	Rectangle(_dc, -1, -1, pResolution.x + 1, pResolution.y + 1);

	m_pCurLevel->render(_dc);

	// m_SubDC를 m_DC로 복사
	//			복사시킬 목적지		 /			복사받을 영역				/ 복사해올 DC / 어디서부터 복사할 것인가			
	BitBlt(MyEngine::GetInst()->GetMainDC(), 0, 0, pResolution.x, pResolution.y, _dc, 0, 0, SRCCOPY);
}
