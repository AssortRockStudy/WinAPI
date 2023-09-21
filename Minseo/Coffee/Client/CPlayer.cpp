#include "pch.h"
#include "CPlayer.h"

// Manager
#include "CTimeMgr.h"
#include "CKeyMgr.h"
#include "CLevelMgr.h"
#include "CLevel.h"
#include "CPathMgr.h"

// 파생 오브젝트
#include "CProjectile.h"
#include "CMissile1.h"
#include "CMissile2.h"
#include "CMissile3.h"

// Engine
#include "CEngine.h"


CPlayer::CPlayer()
	:m_Speed(500.f) 
	,m_Image(nullptr)
	//,m_Acc(0) // 근데 나중에 게임 시간이 얼마나 흘렀는지 체크하기 위해서 m_Acc를 사용할 일이 있을 것 같음. 
	// 물론 여기서 사용하는 것은 아니고 레벨 단위로 만들겠지만.
{
	// 이미지가 존재하는 상대 경로
	wstring strPath = CPathMgr::GetContentPath();
	strPath += L"texture\\fighter.bmp";

	// 내가 로딩하려는 파일의 크기를 재서 원본 파일과 같은 크기의 비트맵에 데이터를 그대로 옮겨와서 이미지와 동일한 비트맵 조각이 만들어짐.
	m_Image = (HBITMAP)LoadImage(nullptr, strPath.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE|LR_CREATEDIBSECTION); // 이미지 로딩
	m_ImageDC = CreateCompatibleDC(CEngine::GetInst()->GetMainDC());

	// select로 1x1 비트맵 빼고 비행기 이미지 넣은 다음, 원본 1x1 비트맵은 반환 되자 마자 삭제
	DeleteObject(SelectObject(m_ImageDC, m_Image));

	// m_BitMapInfo에 GetObject함수를 사용해 이미지를 비트맵에 저장
	GetObject(m_Image, sizeof(BITMAP), &m_BitmapInfo); 

}

CPlayer::~CPlayer()
{
	DeleteObject(m_Image);
}

void CPlayer::tick(float _DT)
{
	Vec2 vPos = GetPos();
	// 만약 왼 쪽 방향키가 눌려있다면 반환으로 0x8000이 반환되는데, 
	// 이 때 0x8001과 비트 연산을 해서 결과적으로 0x8000으로 방향키가 눌려있는지 판단한다.

	if (KEY_PRESSED(LEFT))
	{
		vPos.x -= m_Speed * _DT;
	}
	if (KEY_PRESSED(RIGHT))
	{
		vPos.x += m_Speed * _DT;
	}
	if (KEY_PRESSED(UP))
	{
		vPos.y -= m_Speed * _DT;
	}
	
	if (KEY_PRESSED(DOWN))
	{
		vPos.y += m_Speed * _DT;
	}

	if (KEY_TAP(SPACE))
	{
		CLevel* pCurLevel = CLevelMgr::GetInst()->GetCurLevel();

		for (int i = 0; i < 3; ++i)
		{
			CProjectile* pProjectile = new CProjectile; // 새롭게 동적 할당

			Vec2 ProjectilePos = GetPos();
			pProjectile->SetPos(ProjectilePos);

			ProjectilePos.y -= GetScale().y / 2.f;
			pProjectile->SetScale(Vec2(25.f, 25.f));

			pProjectile->SetSpeed(1000.f); // 빠른 총알...
			pProjectile->SetDir(PI / 4.f + (PI / 4.f) * (float)i); // 각도를 45 + (45*i)로 계산해서 넣기(총 3발)

			pCurLevel->AddObject(pProjectile); // 레벨에 넣어서 지속적으로 움직이게 하기, 나중에 할당 해제하기
		}
	}

	if (KEY_TAP(_1))
	{
		CLevel* pCurLevel = CLevelMgr::GetInst()->GetCurLevel();

		CMissile1* pMissile1 = new CMissile1; // 새롭게 동적 할당

		Vec2 MissilePos = GetPos();
		pMissile1->SetPos(MissilePos);
		pMissile1->SetScale(Vec2(25.f, 25.f));
		pMissile1->SetSpeed(1000.f); // 빠른 총알...
		pMissile1->SetTarget(pCurLevel->GetCurruntMonster(MissilePos));
		pCurLevel->AddObject(pMissile1); // 레벨에 넣어서 지속적으로 움직이게 하기, 나중에 할당 해제하기
		
	}
	if (KEY_TAP(_2))
	{
		CLevel* pCurLevel = CLevelMgr::GetInst()->GetCurLevel();

		CMissile2* pMissile2 = new CMissile2; // 새롭게 동적 할당

		Vec2 MissilePos = GetPos();
		pMissile2->SetPos(MissilePos);
		pMissile2->SetScale(Vec2(25.f, 25.f));
		pMissile2->SetSpeed(300.f); // 빠른 총알...
		pMissile2->SetTarget(pCurLevel->GetCurruntMonster(MissilePos));
		pCurLevel->AddObject(pMissile2); // 레벨에 넣어서 지속적으로 움직이게 하기, 나중에 할당 해제하기

	}
	if (KEY_PRESSED(_3))
	{
		CLevel* pCurLevel = CLevelMgr::GetInst()->GetCurLevel();

		CMissile3* pMissile3 = new CMissile3; // 새롭게 동적 할당

		Vec2 MissilePos = GetPos();
		pMissile3->SetPos(MissilePos);
		pMissile3->SetScale(Vec2(25.f, 25.f));
		pMissile3->SetSpeed(1000.f); // 빠른 총알...
		pMissile3->SetTarget(pCurLevel->GetCurruntMonster(MissilePos));
		pCurLevel->AddObject(pMissile3); // 레벨에 넣어서 지속적으로 움직이게 하기, 나중에 할당 해제하기

	}
	//m_Acc += _DT; 간략하게 전체 시간 구하기
	SetPos(vPos);
}

void CPlayer::render(HDC _dc)
{
	Vec2 pos = GetPos();
	Vec2 sca = GetScale();
	HPEN RedPen = CreatePen(PS_SOLID, 1, RGB(255, 50, 50));
	HPEN PrevPen = (HPEN)SelectObject(_dc, RedPen);

	// HBRUSH 를 사용해서 브러시도 똑같이 만들 수 있다.

	TransparentBlt(_dc, (int)pos.x - m_BitmapInfo.bmWidth / 2
		, (int)pos.y - m_BitmapInfo.bmHeight / 2
		, m_BitmapInfo.bmWidth
		, m_BitmapInfo.bmHeight
		, m_ImageDC
		, 0, 0
		, m_BitmapInfo.bmWidth
		, m_BitmapInfo.bmHeight
		, RGB(255, 0, 255));
	
	//SelectObject(_dc, PrevPen);

	//DeleteObject(RedPen);
	//DeleteObject(PrevPen);

}
