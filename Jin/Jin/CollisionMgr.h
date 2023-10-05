#pragma once

class Collider;

class CollisionMgr
{
	SINGLETON(CollisionMgr);

private:
	UINT m_LayerCheck[32];

public:
	void tick();
	void CheckCollision(LAYER _Left, LAYER _Right);
	void UncheckCollision(LAYER _Left, LAYER _Right);

private:
	void CollisionBtwLayer(LAYER _Left, LAYER _Right);
	bool IsCollision(Collider* _Left, Collider* _Right);
};

