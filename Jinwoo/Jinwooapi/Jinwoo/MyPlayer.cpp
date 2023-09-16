#include "pch.h"
#include "MyPlayer.h"

#include "MyEngine.h"

#include "MyTimeMgr.h"
#include "MyKeyMgr.h"
#include "MyLevelMgr.h"
#include "MyPathMgr.h"

#include "MyLevel.h"
#include "MyProjectile.h"

#include "MyCollider.h"

#include "HomingBullet.h"
#include "MyMonster.h"

MyPlayer::MyPlayer() : m_Speed(300.f), m_PlayerImage(nullptr)
{
	// 이미지가 존재하는 경로 탐색
	wstring strPath = MyPathMgr::GetContentPath();
	strPath += L"Fighter.bmp";

	// Player가 사용하는 Component 추가
	m_Collider = AddComponent<MyCollider>();
	m_Collider->SetOffsetPos(Vec2(0.f, 10.f));
	m_Collider->SetOffsetScale(Vec2(40.f, 80.f));

	// 플레이어가 사용할 이미지 로드
	m_PlayerImage = (HBITMAP)LoadImage(nullptr, strPath.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	m_PlayerDC = CreateCompatibleDC(MyEngine::GetInst()->GetMainDC());
	DeleteObject(SelectObject(m_PlayerDC, m_PlayerImage));
	GetObject(m_PlayerImage, sizeof(BITMAP), &m_BitmapInfo);
}

MyPlayer::~MyPlayer()
{
	DeleteObject(m_PlayerImage);
	DeleteDC(m_PlayerDC);
}

void MyPlayer::tick(float _DT)
{
	ParentClass::tick(_DT);

	Vec2 vPos = GetPos();

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
		MyLevel* pCurLevel = MyLevelMgr::GetInst()->GetCurLevel();

		HomingBullet* HBullet = new HomingBullet;

		Vec2 HbulletPos = GetPos();
		HbulletPos.y -= GetScale().y / 2.f;

		HBullet->SetSpeed(300.f);
		HBullet->SetAngle(PI / 2.f);
		HBullet->SetPos(HbulletPos);
		HBullet->SetScale(Vec2(20.f, 20.f));
		HBullet->SetDir(Vec2(0.f, -1.f));
		
		MyTaskMgr::GetInst()->AddTask(FTask{ TASK_TYPE::CREATE_OBJECT, (UINT_PTR)LAYER::PLAYERBULLET, (UINT_PTR)HBullet });
	}

	SetPos(vPos);
}

void MyPlayer::render(HDC _dc)
{
	Vec2 vPos = GetRenderPos();
	Vec2 vScale = GetScale();

	//BitBlt(_dc,
	//	(int)(vPos.x -= m_BitmapInfo.bmWidth / 2),
	//	(int)(vPos.y -= m_BitmapInfo.bmHeight / 2),
	//	m_BitmapInfo.bmWidth,
	//	m_BitmapInfo.bmHeight,
	//	m_PlayerDC,
	//	0, 0, SRCCOPY);

	TransparentBlt(_dc,
		(int)(vPos.x -= m_BitmapInfo.bmWidth / 2.f),
		(int)(vPos.y -= m_BitmapInfo.bmHeight / 2.f),
		m_BitmapInfo.bmWidth,
		m_BitmapInfo.bmHeight,
		m_PlayerDC,
		0, 0,
		m_BitmapInfo.bmWidth,
		m_BitmapInfo.bmHeight,
		RGB(255, 0, 255));

	ParentClass::render(_dc);
}
