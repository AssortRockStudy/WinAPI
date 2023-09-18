#pragma once

class CCollider;

class CCollisionMgr
{
	SINGLETON(CCollisionMgr);

private:
	UINT		m_LayerCheck[(UINT)LAYER::END];


public:
	void tick();
	void CheckCollision(LAYER _eLeft, LAYER _eRight);
	void UnCheck(LAYER _eLeft, LAYER _eRight);

private:
	void CollisionBtwLayer(LAYER _eLeft, LAYER _eRight);
	bool IsCollision(CCollider* _pLeft, CCollider* _pRight);

};

