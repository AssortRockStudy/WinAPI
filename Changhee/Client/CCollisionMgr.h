#pragma once


class CCollisionMgr
{
	SINGLETON(CCollisionMgr);

private:
	UINT		m_LayerCheck[(UINT)LAYER::END];


public:
	void tick();
	void CheckCollision(LAYER _eLeft, LAYER _eRight);
	void UnCheck(LAYER _eLeft, LAYER _eRight);


};

