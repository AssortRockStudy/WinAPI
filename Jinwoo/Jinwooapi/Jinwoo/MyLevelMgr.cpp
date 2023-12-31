#include "pch.h"
#include "MyLevelMgr.h"

#include "MyEngine.h"

#include "MyCameraMgr.h"
#include "MyColliderMgr.h"
#include "MyLogMgr.h"

#include "MyLevel.h"
#include "MyStartLevel.h"
#include "MyPlayLevel.h"
#include "MyEditLevel.h"

#include "MyPlayer.h"
#include "MyMonster.h"
#include "MyPlatform.h"

MyLevelMgr::MyLevelMgr() : m_pCurLevel(nullptr)
{

}

MyLevelMgr::~MyLevelMgr()
{
	for (UINT i = 0; i < (UINT)LEVEL_TYPE::END; ++i)
	{
		if (nullptr != m_arrLevels[i])
		{
			delete m_arrLevels[i];
		}
	}
}

void MyLevelMgr::ChangeLevel(LEVEL_TYPE _Type)
{
	// 같은 레벨로 변경하려 할 경우
	if (m_pCurLevel == m_arrLevels[(UINT)_Type])
	{
		return;
	}

	// 기존에 다른 레벨을 실행중일 경우 기존 레벨 exit
	if (nullptr != m_pCurLevel)
	{
		m_pCurLevel->exit();
	}

	m_pCurLevel = m_arrLevels[(UINT)_Type];

	m_pCurLevel->enter();

	m_pCurLevel->begin();
}

void MyLevelMgr::init()
{
	// 모든 레벨 생성
	m_arrLevels[(UINT)LEVEL_TYPE::START_LEVEL] = new MyStartLevel;
	m_arrLevels[(UINT)LEVEL_TYPE::PLAY_LEVEL] = new MyPlayLevel;
	m_arrLevels[(UINT)LEVEL_TYPE::EDITOR_LEVEL] = new MyEditLevel;

	// 레벨 초기화
	for (UINT i = 0; i < (UINT)LEVEL_TYPE::END; ++i)
	{
		m_arrLevels[i]->init();
	}

	//// 초기 레벨을 PLAY_LEVEL로 설정
	//m_pCurLevel = m_arrLevels[(UINT)LEVEL_TYPE::PLAY_LEVEL];

	// ::를 사용하여 전역함수를 사용하겠다고 명시
	::ChangeLevel(LEVEL_TYPE::EDITOR_LEVEL);
}

void MyLevelMgr::tick()
{
	if (nullptr != m_pCurLevel)
	{
		m_pCurLevel->tick();
	}
}

void MyLevelMgr::render(HDC _dc)
{
	if (nullptr == m_pCurLevel)
	{
		return;
	}

	POINT pResolution = MyEngine::GetInst()->GetMainResolution();

	// 화면에 출력되지 않는 SubDC에 새로운 사각형을 그려서 화면을 지운 것처럼 활용
	// 똑같은 크기를 사용할 경우 미세한 테두리가 생기기 때문에 1픽셀씩 더 넓혀서 생성
	Rectangle(_dc, -1, -1, pResolution.x + 1, pResolution.y + 1);

	m_pCurLevel->render(_dc);

	// 로그 렌더
	MyLogMgr::GetInst()->tick(_dc);

	// m_SubDC를 m_DC로 복사
	//			복사시킬 목적지		 /			복사받을 영역				/ 복사해올 DC / 어디서부터 복사할 것인가			
	BitBlt(MyEngine::GetInst()->GetMainDC(), 0, 0, pResolution.x, pResolution.y, _dc, 0, 0, SRCCOPY);
}
