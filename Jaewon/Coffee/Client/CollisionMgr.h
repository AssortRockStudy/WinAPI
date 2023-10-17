#pragma once
class Collider;

struct COLLIDER_ID {
	INT_PTR l;
	INT_PTR r;

	bool operator == (const COLLIDER_ID& _oth) const
	{
		if (l == _oth.l && r == _oth.r)
			return true;
		return false;
	}

	bool operator < (const COLLIDER_ID& _oth) const
	{
		if (l < _oth.l)
			return true;
		else if (l > _oth.l)
			return false;
		else
		{
			if (r < _oth.r)
				return true;
			else
				return false;
		}
	}

	COLLIDER_ID()
		: l(0)
		, r(0)
	{}

	COLLIDER_ID(INT_PTR _l, INT_PTR _r)
		: l(_l)
		, r(_r)
	{}
};

class CollisionMgr
{
	SINGLETON(CollisionMgr);

private:
	UINT mLayerChk[32];
	map<COLLIDER_ID, bool> mapID;

private:
	void collisionBtwLayer(LAYER l, LAYER r);
	bool isCollision(Collider* l, Collider* r);

public:
	void tick();
	void checkCollision(LAYER l, LAYER r);
	void unCheckCollision(LAYER l, LAYER r);
};

