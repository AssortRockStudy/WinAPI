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
#include "CAssetMgr.h"
#include "CTexture.h"
#include "Animator.h"
#include "LogMgr.h"
#include "Anim.h"

void Player::tick(float _dt)
{
	Super::tick(_dt);

	Vec2 vPos = getPos();

	// 키입력(이전에 누른 적이 있고 호출 시점에도 눌려있는 상태)이 발생하면 true
	// 좌표의 이동 거리 = 속도*dt
	if (reverseMove == true) {
		if (KeyMgr::GetInst()->getKeyState(A) == PRESSED) {
			vPos.x -= mSpeed * _dt;
			mAnimator->play(L"WalkLeft", true);
		}
		if (KeyMgr::GetInst()->getKeyState(A) == RELEASED)
			mAnimator->play(L"IdleLeft", true);
		if (KeyMgr::GetInst()->getKeyState(D) == PRESSED) {
			vPos.x += mSpeed * _dt;
			mAnimator->play(L"WalkRight", true);
		}
		if (KeyMgr::GetInst()->getKeyState(D) == RELEASED)
			mAnimator->play(L"IdleRight", true);
		if (KeyMgr::GetInst()->getKeyState(W) == PRESSED) {
			vPos.y -= mSpeed * _dt;
			mAnimator->play(L"WalkUp", true);
		}
		if (KeyMgr::GetInst()->getKeyState(W) == RELEASED)
			mAnimator->play(L"IdleUp", true);
		if (KeyMgr::GetInst()->getKeyState(S) == PRESSED) {
			vPos.y += mSpeed * _dt;
			mAnimator->play(L"WalkDown", true);
		}
		if (KeyMgr::GetInst()->getKeyState(S) == RELEASED)
			mAnimator->play(L"IdleDown", true);
		if (KeyMgr::GetInst()->getKeyState(SPACE) == TAP) {
			
			CLevel* curLevel = LevelMgr::GetInst()->getCurLevel();
			
			Guided* mProjectile = new Guided;

			mProjectile->setSpeed(500.f);
			mProjectile->setAngle(M_PI / 2.f);
			mProjectile->setPos(getPos());
			mProjectile->setScale(Vec2{ 25.f, 25.f });
			mProjectile->SetDir(Vec2(0.f, -1.f));
			TaskMgr::GetInst()->addTask(FTask{ CREATE_OBJECT, PLAYER_PJ, (UINT_PTR)mProjectile });

			LOG(WARNING, L"Shoot");
			
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

void Player::overLap(Collider* myCol, CObj* _othObj, Collider* _othCol)
{
	myCol->getName();
}

Player::Player():mSpeed(500.f), col(black), reverseMove(true), pImage(nullptr), pImageDc(nullptr)
{
	CTexture* pAtlas = CAssetMgr::GetInst()->LoadTexture(L"PlayerAtlas", L"texture\\link.bmp");

	mAnimator = addComponent<Animator>(L"Animator");
	mAnimator->createAnimation(L"WalkDown", pAtlas, Vec2(0.f, 520.f), Vec2(120, 130), Vec2(0.f, -60.f), 0.05f, 10);
	mAnimator->createAnimation(L"WalkLeft", pAtlas, Vec2(0.f, 650.f), Vec2(120, 130), Vec2(0.f, -60.f), 0.05f, 10);
	mAnimator->createAnimation(L"WalkUp", pAtlas, Vec2(0.f, 780.f), Vec2(120, 130), Vec2(0.f, -60.f), 0.05f, 10);
	mAnimator->createAnimation(L"WalkRight", pAtlas, Vec2(0.f, 910.f), Vec2(120, 130), Vec2(0.f, -60.f), 0.05f, 10);

	mAnimator->createAnimation(L"IdleDown", pAtlas, Vec2(0.f, 0.f), Vec2(120, 130), Vec2(0.f, -60.f), 0.05f, 3);
	mAnimator->createAnimation(L"IdleLeft", pAtlas, Vec2(0.f, 130.f), Vec2(120, 130), Vec2(0.f, -60.f), 0.05f, 3);
	mAnimator->createAnimation(L"IdleUp", pAtlas, Vec2(0.f, 260.f), Vec2(120, 130), Vec2(0.f, -60.f), 0.05f, 1);
	mAnimator->createAnimation(L"IdleRight", pAtlas, Vec2(0.f, 390.f), Vec2(120, 130), Vec2(0.f, -60.f), 0.05f, 3);

	mAnimator->play(L"WalkDown", true);

	mCollider = addComponent<Collider>(L"PlayerCollider");
	mCollider->setOffsetPos(Vec2(0.f, 10.f));
	mCollider->setScale(Vec2(40.f, 80.f));
	mCollider->setOffsetPos(Vec2(0.f, -40.f));

	mTexture = CAssetMgr::GetInst()->LoadTexture(L"PlayerTexture", L"texture\\fighter.bmp");
	
}

Player::~Player()
{
}
