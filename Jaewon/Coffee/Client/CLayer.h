#pragma once
#include "CEntity.h"
// ������Ʈ�� �����ϴ� ����
// ������ �������� �ϴ� ������ �ϸ�
// ������ ���� ���̾ �����ϴ� ������ ���� ������ ����

class CObj;

class CLayer : public CEntity
{
private:
	vector<CObj*> mVecObjects;

public:
	void tick();
	void render(HDC _dc);

public:
	void AddObj(CObj* _obj) {
		mVecObjects.push_back(_obj);
	}

public:
	CLayer();
	~CLayer();

	friend class CLevel;

};

