#include "pch.h"
#include "Player.h"
#include "KeyMgr.h"
#include "CLevel.h"
#include "LevelMgr.h"
#include "CProjectile.h"
#include "Guided.h"
#include "CPathMgr.h"
#include "CEngine.h"

void Player::tick(float _dt)
{
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
			curLevel->addObject(PLAYER_PJ ,mProjectile);
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
	Vec2 vPos = getPos();
	Vec2 vScale = getScale();

	// 펜, 브러쉬 생성
	// 현재 사용하던 객체를 따로 저장해두고
	// 새로 만든 펜을 dc에 바꿔둠

	/*
	HPEN renderPen;
	HBRUSH renderBrush;
	if (col == red) {
		renderPen = CREATEREDPEN;
		renderBrush = CREATEREDBRUSH;
			
	}
	else {
		renderPen = CREATEBLACKPEN;
		renderBrush = CREATEBLACKBRUSH;
	}
	HPEN prevPen = (HPEN)SelectObject(_dc, renderPen);
	HBRUSH prevBrush = (HBRUSH)SelectObject(_dc, renderBrush);
	*/
	
	
	BitBlt(_dc, vPos.x - pBitMapInfo.bmWidth / 2.f
		, vPos.y - pBitMapInfo.bmHeight / 2.f
		, pBitMapInfo.bmWidth
		, pBitMapInfo.bmHeight
		, pImageDc
		, 0, 0, SRCCOPY);

	// 렌더링 끝나고 다시 바꾸고
	// 만들었던 펜 삭제
	/*
	SelectObject(_dc, prevPen);
	DeleteObject(renderPen);

	SelectObject(_dc, prevBrush);
	DeleteObject(renderBrush);
	*/
}

Player::Player():mSpeed(500.f), col(black), reverseMove(true), pImage(nullptr), pImageDc(nullptr)
{
	// 이미지 불러오기
	wstring strPath = CPathMgr::getContentPath();
	strPath += L"texture\\Fighter.bmp";
	//MessageBox(nullptr, CPathMgr::getContentPath(), L"Current Directory Check", MB_OK);

	// 비트맵 로딩
	pImage = (HBITMAP)LoadImage(nullptr, strPath.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	pImageDc = CreateCompatibleDC(CEngine::GetInst()->getMainDc());
	DeleteObject((SelectObject(pImageDc, pImage)));
	GetObject(pImage, sizeof(BITMAP), &pBitMapInfo);
	
}

Player::~Player()
{
}
