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
#include "CCollider.h"

class CCollider;


using std::wstring;

CPlayer::CPlayer()
	: m_Speed(500.f)
	, m_Image(nullptr)
{
	//이미지가 존재하는 상대경로 (contents 폴더로 부터)
	//힙메모리에할당
	wstring strPath = CPathMgr::GetContentDir();
	strPath+= L"texture\\Fighter.bmp";

	// 필요한 컴포넌트 추가
	m_Collider = AddComponent<CCollider>();
	//AddComponent<CAnimator>();
	//AddComponent<CMovement>();


	m_Image= (HBITMAP)LoadImage(nullptr, strPath.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	m_ImageDC = CreateCompatibleDC(CEngine::GetInst()->GetMainDC());
	DeleteObject(SelectObject(m_ImageDC, m_Image));
 	GetObject(m_Image, sizeof(BITMAP), &m_BitmapInfo);
}

CPlayer::~CPlayer()
{
	//DeleteObject(hLoadBit);
	DeleteObject(m_Image);
	DeleteDC(m_ImageDC);
}

void CPlayer::tick(float _DT)
{
	Vec2 vPos = GetPos();

	// 키입력이 발생하면 움직인다.
	if (KEY_PRESSED(A))
	{
		vPos.x -= m_Speed * _DT;
	}

	if (KEY_PRESSED(D))
	{
		vPos.x += m_Speed * _DT;
	}

	if (KEY_PRESSED(W))
	{
		vPos.y -= m_Speed * _DT;
	}

	if (KEY_PRESSED(S))
	{
		vPos.y += m_Speed * _DT;
	}

	if (KEY_TAP(SPACE))
	{
		CLevel* pCurLevel = CLevelMgr::GetInst()->GetCurLevel();

		for (int i = 0; i < 3; ++i)
		{
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

			pCurLevel->AddObject(PLAYER_PJ, pProjectile);

			CTaskMgr::GetInst()->AddTask(FTask{ CREATE_OBJECT, PLAYER_PJ, (UINT_PTR)pProjectile });
		}
	}
	SetPos(vPos);
}


void CPlayer::render(HDC _dc)
{
	Vec2 vPos = GetRenderPos();
	Vec2 vScale = GetScale();
	SelectObject(_dc, CPal::GetInst()->getHPen(BLACK));
	SelectObject(_dc, CPal::GetInst()->getHBrush(BLACK));
	
	/*BitBlt(_dc, (int)vPos.x - m_BitmapInfo.bmWidth / 2
				, (int)vPos.y - m_BitmapInfo.bmHeight / 2
				, m_BitmapInfo.bmWidth
				, m_BitmapInfo.bmHeight
				, m_ImageDC
				, 0, 0, SRCCOPY);*/
	TransparentBlt(_dc, (int)vPos.x - m_BitmapInfo.bmWidth / 2
		, (int)vPos.y - m_BitmapInfo.bmHeight / 2
		, m_BitmapInfo.bmWidth
		, m_BitmapInfo.bmHeight
		, m_ImageDC
		, 0, 0
		, m_BitmapInfo.bmWidth
		, m_BitmapInfo.bmHeight
		, RGB(255, 0, 255));


	//Rectangle(_dc
	//	, int(vPos.x - vScale.x / 2)
	//	, int(vPos.y - vScale.y / 2)
	//	, int(vPos.x + vScale.x / 2)
	//	, int(vPos.y + vScale.y / 2));

}