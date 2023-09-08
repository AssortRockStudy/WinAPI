#include "pch.h"
#include "Player.h"

void Player::tick(float _dt)
{
	Vec2 vPos = getPos();

	// Ű�Է�(������ ���� ���� �ְ� ȣ�� �������� �����ִ� ����)�� �߻��ϸ� true
	// ��ǥ�� �̵� �Ÿ� = �ӵ�*dt
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

	// ��, �귯�� ����
	// ���� ����ϴ� ��ü�� ���� �����صΰ�
	// ���� ���� ���� dc�� �ٲ��

	HPEN blackPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	HPEN prevPen = (HPEN)SelectObject(_dc, blackPen);

	HBRUSH blackBrush = CreateSolidBrush(RGB(0, 0, 0));
	HBRUSH prevBrush = (HBRUSH)SelectObject(_dc, blackBrush);
	
	Rectangle(_dc
		, int(vPos.x - vScale.x / 2)
		, int(vPos.y - vScale.y / 2)
		, int(vPos.x + vScale.x / 2)
		, int(vPos.y + vScale.y / 2));

	// ������ ������ �ٽ� �ٲٰ�
	// ������� �� ����
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
