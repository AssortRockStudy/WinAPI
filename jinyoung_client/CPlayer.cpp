#include "pch.h"
#include "CPlayer.h"

#include "CTimeManager.h"
#include "CPal.h"
#include "CKeyman.h"

#include "CLevelMgr.h"
#include "CLevel.h"
#include "CProjectile.h"

#include "CPathMgr.h"
#include "CEngine.h"

#include "CGuided.h"

#include "CAssetMgr.h"
#include "CTexture.h"

#include "CLogMgr.h"

#include "components.h"
/*
#include "CCollider.h"
#include "CAnimator.h"
#include "CAnim.h"*/

class CCollider;


using std::wstring;

CPlayer::CPlayer()
	: m_Speed(500.f)
	//, m_Image(nullptr)
{
	//이미지가 존재하는 상대경로 (contents 폴더로 부터)
	//힙메모리에할당
	//wstring strPath = CPathMgr::GetContentDir();
	//strPath+= L"texture\\Fighter.bmp";

	// 애니메이터 컴포넌트 추가
	CTexture* pAtlas = CAssetMgr::GetInst()->LoadTexture(L"PlayerAtlas", L"texture\\link.bmp");

	m_Animator = AddComponent<CAnimator>(L"Animator");
	//m_Animator->CreateAnimation(L"WalkDown", pAtlas, Vec2(0.f, 520.f), Vec2(120, 130), Vec2(0.f, -60.f), 0.05f, 10);
	//m_Animator->CreateAnimation(L"WalkLeft", pAtlas, Vec2(0.f, 650.f), Vec2(120, 130), Vec2(0.f, -60.f), 0.05f, 10);
	//m_Animator->CreateAnimation(L"WalkUp", pAtlas, Vec2(0.f, 780.f), Vec2(120, 130), Vec2(0.f, -60.f), 0.05f, 10);
	//m_Animator->CreateAnimation(L"WalkRight", pAtlas, Vec2(0.f, 910.f), Vec2(120, 130), Vec2(0.f, -60.f), 0.05f, 10);	
	//m_Animator->CreateAnimation(L"IdleDown", pAtlas, Vec2(0.f, 0.f), Vec2(120, 130), Vec2(0.f, -60.f), 0.05f, 3);
	//m_Animator->CreateAnimation(L"IdleLeft", pAtlas, Vec2(0.f, 130.f), Vec2(120, 130), Vec2(0.f, -60.f), 0.05f, 3);
	//m_Animator->CreateAnimation(L"IdleUp", pAtlas, Vec2(0.f, 260.f), Vec2(120, 130), Vec2(0.f, -60.f), 0.05f, 1);
	//m_Animator->CreateAnimation(L"IdleRight", pAtlas, Vec2(0.f, 390.f), Vec2(120, 130), Vec2(0.f, -60.f), 0.05f, 3);
	//m_Animator->SaveAnimations(L"animdata");

	m_Animator->LoadAnimation(L"animdata\\IdleDown.txt");
	m_Animator->LoadAnimation(L"animdata\\IdleLeft.txt");
	m_Animator->LoadAnimation(L"animdata\\IdleRight.txt");
	m_Animator->LoadAnimation(L"animdata\\IdleUp.txt");
	m_Animator->LoadAnimation(L"animdata\\WalkDown.txt");
	m_Animator->LoadAnimation(L"animdata\\WalkLeft.txt");
	m_Animator->LoadAnimation(L"animdata\\WalkRight.txt");
	m_Animator->LoadAnimation(L"animdata\\WalkUp.txt");


	m_Animator->Play(L"WalkDown", true);

	//m_Animator = AddComponent<CAnimator>(L"Animator");

	// 충돌체 컴포넌트 추가
	m_Collider = AddComponent<CCollider>(L"PlayerCollider");
	m_Collider->SetOffsetPos(Vec2(0.f, 10.f));
	m_Collider->SetScale(Vec2(40.f, 80.f));
	m_Collider->SetOffsetPos(Vec2(0.f, -40.f));
	//AddComponent<CAnimator>();
	//AddComponent<CMovement>();
	// 이미지가 존재하는 상대경로(constent 폴더로부터)
	//m_pTexture = CAssetMgr::GetInst()->LoadTexture(L"PlayerTexture", L"texture\\fighter.bmp");


	// Movement 컴포넌트 추가
	m_Movement = AddComponent<CMovement>(L"PlayerMovement");
	m_Movement->SetMass(1.f);
	m_Movement->SetInitSpeed(50.f);
	m_Movement->SetInitSpeed(400.f);
	m_Movement->UseGravity(true);
	m_Movement->SetGravityDir(Vec2(0.f, 1.f));
	m_Movement->SetFrictionScale(0.f);

	//m_Image= (HBITMAP)LoadImage(nullptr, strPath.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	//m_ImageDC = CreateCompatibleDC(CEngine::GetInst()->GetMainDC());
	//DeleteObject(SelectObject(m_ImageDC, m_Image));
 //	GetObject(m_Image, sizeof(BITMAP), &m_BitmapInfo);
}

CPlayer::~CPlayer()
{
	//DeleteObject(hLoadBit);
	//DeleteObject(m_Image);
	//DeleteDC(m_ImageDC);
}

void CPlayer::tick(float _DT)
{
	Super::tick(_DT);

	Vec2 vPos = GetPos();

	if (KEY_PRESSED(A))
	{
		vPos.x -= m_Speed * _DT;
		m_Animator->Play(L"WalkLeft", true);
	}

	if (KEY_RELEASED(A))
	{
		m_Animator->Play(L"IdleLeft", true);
	}

	if (KEY_PRESSED(D))
	{
		vPos.x += m_Speed * _DT;
		m_Animator->Play(L"WalkRight", true);
	}
	if (KEY_RELEASED(D))
	{
		m_Animator->Play(L"IdleRight", true);
	}


	if (KEY_PRESSED(W))
	{
		vPos.y -= m_Speed * _DT;
		m_Animator->Play(L"WalkUp", true);
	}
	if (KEY_RELEASED(W))
	{
		m_Animator->Play(L"IdleUp", true);
	}

	if (KEY_PRESSED(S))
	{
		vPos.y += m_Speed * _DT;
		m_Animator->Play(L"WalkDown", true);
	}
	if (KEY_RELEASED(S))
	{
		m_Animator->Play(L"IdleDown", true);
	}

	if (KEY_TAP(SPACE))
	{
		CLevel* pCurLevel = CLevelMgr::GetInst()->GetCurLevel();

		//CProjectile* pProjectile = new CProjectile;
		CGuided* pProjectile = new CGuided;
		
		Vec2 ProjectilePos = GetPos();
		ProjectilePos.y -= GetScale().y / 2.f;
		
		pProjectile->SetSpeed(500.f);
		pProjectile->SetAngle(PI / 2.f);
		
		
		//pProjectile->SetSpeed(1000.f);
		//pProjectile->SetDir(PI / 4.f + (PI / 4.f) * (float)i);
		pProjectile->SetPos(ProjectilePos);
		pProjectile->SetScale(Vec2(25.f, 25.f));
		pProjectile->SetDir(Vec2(0.f, -1.f));
		
		//pCurLevel->AddObject(pProjectile);
		
		//pCurLevel->AddObject(PLAYER_PJ, pProjectile);
		
		CTaskMgr::GetInst()->AddTask(FTask{ CREATE_OBJECT, PLAYER_PJ, (UINT_PTR)pProjectile });

		wstring strLogMessage = L"Shoot ";
		string funcname = __FUNCTION__;
		strLogMessage += wstring(funcname.begin(), funcname.end());
		strLogMessage += L"  Line : ";
		wchar_t szBuffer[20] = {};
		_itow_s(__LINE__, szBuffer, 20, 10);
		strLogMessage += szBuffer;
		CLogMgr::GetInst()->AddLog(FLog{ LOG_LEVEL::LOG, strLogMessage });
	}
	SetPos(vPos);
}


//void CPlayer::render(HDC _dc)
//{
//	Vec2 vPos = GetRenderPos();
//	Vec2 vScale = GetScale();
//	SelectObject(_dc, CPal::GetInst()->getHPen(BLACK));
//	SelectObject(_dc, CPal::GetInst()->getHBrush(BLACK));
//	
//
//	UINT width = m_pTexture->GetWidth();
//	UINT height = m_pTexture->GetHeight();
//
//
//	TransparentBlt(_dc
//		, (int)vPos.x - width / 2
//		, (int)vPos.y - height / 2
//		, width
//		, height
//		, m_pTexture->GetDC()
//	/*BitBlt(_dc, (int)vPos.x - m_BitmapInfo.bmWidth / 2
//				, (int)vPos.y - m_BitmapInfo.bmHeight / 2
//				, m_BitmapInfo.bmWidth
//				, m_BitmapInfo.bmHeight
//				, m_ImageDC
//				, 0, 0, SRCCOPY);*/
//	//TransparentBlt(_dc, (int)vPos.x - m_BitmapInfo.bmWidth / 2
//	//	, (int)vPos.y - m_BitmapInfo.bmHeight / 2
//	//	, m_BitmapInfo.bmWidth
//	//	, m_BitmapInfo.bmHeight
//	//	, m_ImageDC
//		, 0, 0
//		, width
//		, height
//		//, m_BitmapInfo.bmWidth
//		//, m_BitmapInfo.bmHeight
//		, RGB(255, 0, 255));
//
//	Super::render(_dc);
//
//	//Rectangle(_dc
//	//	, int(vPos.x - vScale.x / 2)
//	//	, int(vPos.y - vScale.y / 2)
//	//	, int(vPos.x + vScale.x / 2)
//	//	, int(vPos.y + vScale.y / 2));
//
//}

void CPlayer::Overlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol)
{
	_OwnCol->GetName();
}