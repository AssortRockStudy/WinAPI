#pragma once
#include "CEntity.h"
// ������Ʈ�� �����ϴ� ����
// ������ �������� �ϴ� ������ �ϸ�
// ������ ���� ���̾ �����ϴ� ������ ���� ������ ����

class CObj;
class Collider;

class CLayer : public CEntity
{
	// �������� ���� �ִ� ��� ���� �� �Լ� ������
private:
	vector<CObj*> mVecObjects;
	vector<Collider*> mVecCollider;

public:
	void begin();
	void tick();
	void finalTick();
	void render(HDC _dc);
	void clear() { mVecCollider.clear(); }

public:
	void AddObj(CObj* _obj) {
		mVecObjects.push_back(_obj);
	}
	void registerCollider(Collider* _col) {mVecCollider.push_back(_col); } 
	const vector<Collider*>& getColliders() { return mVecCollider; }
	void deleteAllObjects();
	const vector<CObj*>& getObjects() { return  mVecObjects; }

public:
	CLayer();
	~CLayer();

	// ������ �������� ���̾ ������ ���� ���� ������ friend Ű���� ���
	friend class CLevel;
	friend class UIMgr;

};

