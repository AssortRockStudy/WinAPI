#include "pch.h"
#include "Player.h"
#include "KeyMgr.h"
#include "CLevel.h"
#include "LevelMgr.h"
#include "CProjectile.h"
#include "Guided.h"
#include "CPathMgr.h"
#include "CEngine.h"
#include "TaskMgr.h"
#include "Collider.h"

void Player::tick(float _dt)
{
	Super::tick(_dt);

	Vec2 vPos = getPos();

	// 키입력(이전에 누른 적이 있고 호출 시점에도 눌려있는 상태)이 발생하면 true
	// 좌표의 이동 거리 = 속도*dt
	if (reverseMove == true) {
		if (KeyMgr::GetInst()->getKeyState(A) == PRESSED)
			vPos.x -= mSpeed * _dt;
		if (KeyMgr::GetInst()->getKeyState(D) == PRESSED)
			vPos.x += mSpeed * _dt;
		if (KeyMgr::GetInst()->getKeyState(W) == PRESSED)
			vPos.y -= mSpeed * _dt;
		if (KeyMgr::GetInst()->getKeyState(S) == PRESSED)
			vPos.y += mSpeed * _dt;
		if (KeyMgr::GetInst()->getKeyState(SPACE) == TAP) {
			
			CLevel* curLevel = LevelMgr::GetInst()->getCurLevel();
			
			Guided* mProjectile = new Guided;

			mProjectile->setSpeed(500.f);
			mProjectile->setAngle(M_PI / 2.f);
			mProjectile->setPos(getPos());
			mProjectile->setScale(Vec2{ 25.f, 25.f });
			mProjectile->SetDir(Vec2(0.f, -1.f));
			TaskMgr::GetInst()->addTask(FTask{ CREATE_OBJECT, PLAYER_PJ, (UINT_PTR)mProjectile });
			
		}
	}
	else {
		if (KeyMgr::GetInst()->getKeyState(A) == PRESSED)
			vPos.x += mSpeed * _dt;
		if (KeyMgr::GetInst()->getKeyState(D) == PRESSED)
			vPos.x -= mSpeed * _dt;
		if (KeyMgr::GetInst()->getKeyState(W) == PRESSED)
			vPos.y += mSpeed * _dt;
		if (KeyMgr::GetInst()->getKeyState(S) == PRESSED)
			vPos.y -= mSpeed * _dt;
	}
	setPos(vPos);
}

void Player::render(HDC _dc)
{
	Vec2 vPos = getRenderPos();
	Vec2 vScale = getScale();

	TransparentBlt(_dc, vPos.x - pBitMapInfo.bmWidth / 2.f
		, vPos.y - pBitMapInfo.bmHeight / 2.f
		, pBitMapInfo.bmWidth
		, pBitMapInfo.bmHeight
		, pImageDc
		, 0, 0
		, pBitMapInfo.bmWidth
		, pBitMapInfo.bmHeight
		, RGB(255, 0, 255));

	Super::render(_dc);
}

Player::Player():mSpeed(500.f), col(black), reverseMove(true), pImage(nullptr), pImageDc(nullptr)
{
	// 이미지 불러오기
	wstring strPath = CPathMgr::getContentPath();
	strPath += L"texture\\Fighter.bmp";
	//MessageBox(nullptr, CPathMgr::getContentPath(), L"Current Directory Check", MB_OK);

	mCollider = addComponent<Collider>();
	mCollider->setOffsetPos(Vec2(0.f, 10.f));
	mCollider->setScale(Vec2(40.f, 80.f));


	// 비트맵 로딩
	pImage = (HBITMAP)LoadImage(nullptr, strPath.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	pImageDc = CreateCompatibleDC(CEngine::GetInst()->getMainDc());
	DeleteObject((SelectObject(pImageDc, pImage)));
	GetObject(pImage, sizeof(BITMAP), &pBitMapInfo);
	
}

Player::~Player()
{
}
