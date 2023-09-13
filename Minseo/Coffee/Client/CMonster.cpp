#include "CMonster.h"


enum DIRECTION
{
	dRIGHT = 0,
	dUP,
	dLEFT,
	dDOWN,
	dEND,	
};

void CMonster::tick(float _DT) // 아잇
{
	Vec2 pos = GetPos();
	static int dir = dRIGHT;

	// PI/2 = 90도. 90도 * 0 = 오른 쪽을 가리키므로 cosf = 750, sinf = 0 이런 느낌으로 나오지 않을까...
	pos.x += m_Speed * cosf(PI / 2 * dir) * _DT; 
	pos.y -= m_Speed * sinf(PI / 2 * dir) * _DT;
	
	if (1.f < m_Time) // 만약 게임 시간 1초가 지난 경우
	{
		++dir; // 방향 전환	
		if (dir == dEND) { dir = 0; } // 방향 0으로
		m_Time = .0f;
	}
	
	m_Time += _DT;
	//POINT point;
	//GetCursorPos(&point);
	//pos.x = (float)point.x;
	//pos.y = (float)point.y;
	SetPos(pos); // 다시 넣어줌
}

CMonster::CMonster()
	:m_Speed(300.f)
	,m_Time(.0f)
{
}

CMonster::~CMonster()
{
}