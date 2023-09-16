#include "pch.h"
#include "CPlayer.h"

#include "CEngine.h"

#include "CKeyMgr.h"
#include "CLevelMgr.h"
#include "CPathMgr.h"
#include "CTaskMgr.h"
#include "CCamera.h"

#include "CCollider.h"


#include "CLevel.h"

#include "CProjectile.h"


CPlayer::CPlayer()
	: m_fSpeed(200.f)
	, m_hImage(nullptr)
{
	wstring strPath = CPathMgr::GetContentDirectory();
	strPath += L"texture\\Fighter.bmp";

	m_hImage = (HBITMAP)LoadImage(nullptr, strPath.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	m_hImageDC = CreateCompatibleDC(CEngine::GetInst()->GetMainDC());
	DeleteObject((HBITMAP)SelectObject(m_hImageDC, m_hImage));

	GetObject(m_hImage, sizeof(BITMAP), &m_BitmapInfo);

	m_pCollider = AddComponent<CCollider>();
	m_pCollider->SetOffsetPos(Vec2(0.f, 10.f));
	m_pCollider->SetScale(Vec2(40.f, 80.f));
}

CPlayer::~CPlayer()
{
	DeleteObject(m_hImage);
	DeleteDC(m_hImageDC);

}



void CPlayer::tick(float _DT)
{
	Super::tick(_DT);

	Vec2 vPos = GetPos();
	
	if (KEY_PRESSED(KEY::W))
	{
		vPos.y -= m_fSpeed * _DT;
	}

	if (KEY_PRESSED(KEY::S))
	{
		vPos.y += m_fSpeed * _DT;
	}
	
	if (KEY_PRESSED(KEY::A))
	{
		vPos.x -= m_fSpeed * _DT;
	}
	
	if (KEY_PRESSED(KEY::D))
	{
		vPos.x += m_fSpeed * _DT;
	}

	if (KEY_TAP(KEY::SPACE))
	{
		CLevel* pCurLevel = CLevelMgr::GetInst()->GetCurLevel();

		CProjectile* pProjectile = new CProjectile;

		Vec2 ProjectilePos = GetPos();
		ProjectilePos.y -= GetScale().y / 2.f;

		pProjectile->SetSpeed(1000.f);
		pProjectile->SetDir(PI / 2.f);
		pProjectile->SetPos(ProjectilePos);
		pProjectile->SetScale(Vec2(25.f, 25.f));

		CTaskMgr::GetInst()->AddTask(FTask{ TASK_TYPE::CREATE_OBJECT, (UINT)LAYER::PLAYER_PJ, (UINT_PTR)pProjectile });

	}

	SetPos(vPos);
}

void CPlayer::render(HDC _dc)
{


	Vec2 vPos = GetRenderPos();
	Vec2 vScale = GetScale();


	TransparentBlt(_dc
		, int(vPos.x - m_BitmapInfo.bmWidth / 2)
		, int(vPos.y - m_BitmapInfo.bmHeight / 2)
		, m_BitmapInfo.bmWidth
		, m_BitmapInfo.bmHeight
		, m_hImageDC, 0, 0
		, m_BitmapInfo.bmWidth
		, m_BitmapInfo.bmHeight
		, RGB(255, 0, 255));

	Super::render(_dc);
}