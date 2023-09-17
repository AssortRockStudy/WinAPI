#pragma once


class CCollisionMgr
{
	SINGLETON(CCollisionMgr);
private:
	// 레이어 간의 충돌을 지정하는 매트릭스
	UINT		m_LayerCheck[32];


public:
	void tick();
	void CheckCollision(LAYER _Left, LAYER _Right);
	void UncheckCollision(LAYER _Left, LAYER _Right);
};
