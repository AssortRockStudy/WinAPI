#pragma once
class CollisionMgr
{
	SINGLETON(CollisionMgr);

private:
	UINT mLayerChk[32];

public:
	void tick();
	void checkCollision(LAYER l, LAYER r);
	void unCheckCollision(LAYER l, LAYER r);
};

