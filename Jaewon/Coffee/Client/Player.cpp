#include "pch.h"
#include "Player.h"

void Player::tick(float _dt)
{
	Vec2 vPos = getPos();

	// 키입력(이전에 누른 적이 있고 호출 시점에도 눌려있는 상태)이 발생하면 true
	// 좌표의 이동 거리 = 속도*dt
	if (GetAsyncKeyState(VK_LEFT) & 0x8001)
		vPos.x -= mSpeed * _dt;
	if (GetAsyncKeyState(VK_RIGHT) & 0x8001)
		vPos.x += mSpeed * _dt;
	if (GetAsyncKeyState(VK_UP) & 0x8001)
		vPos.y -= mSpeed * _dt;
	if (GetAsyncKeyState(VK_DOWN) & 0x8001)
		vPos.y += mSpeed * _dt;
	
	setPos(vPos);
}

void Player::render(HDC _dc)
{
	Vec2 vPos = getPos();
	Vec2 vScale = getScale();

	// 펜, 브러쉬 생성
	// 현재 사용하던 객체를 따로 저장해두고
	// 새로 만든 펜을 dc에 바꿔둠

	HPEN blackPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	HPEN prevPen = (HPEN)SelectObject(_dc, blackPen);

	HBRUSH blackBrush = CreateSolidBrush(RGB(0, 0, 0));
	HBRUSH prevBrush = (HBRUSH)SelectObject(_dc, blackBrush);
	
	Rectangle(_dc
		, int(vPos.x - vScale.x / 2)
		, int(vPos.y - vScale.y / 2)
		, int(vPos.x + vScale.x / 2)
		, int(vPos.y + vScale.y / 2));

	// 렌더링 끝나고 다시 바꾸고
	// 만들었던 펜 삭제
	SelectObject(_dc, prevPen);
	DeleteObject(blackPen);

	SelectObject(_dc, prevBrush);
	DeleteObject(blackBrush);
}

Player::Player():mSpeed(500.f)
{
}

Player::~Player()
{
}
