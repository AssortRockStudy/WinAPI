#pragma once

class MyColliderMgr
{
	SINGLETON(MyColliderMgr);

private:
	UINT m_LayerCheck[32];

public:
	void tick();
	void CheckCollision(LAYER _Left, LAYER _Right);
	void UncheckCollision(LAYER _Left, LAYER _Right);
};

