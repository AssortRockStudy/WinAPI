#pragma once


class CCollisionMgr
{
	SINGLETON(CCollisionMgr);
private:
	// ���̾� ���� �浹�� �����ϴ� ��Ʈ����
	UINT		m_LayerCheck[32];


public:
	void tick();
	void CheckCollision(LAYER _Left, LAYER _Right);
	void UncheckCollision(LAYER _Left, LAYER _Right);
};
