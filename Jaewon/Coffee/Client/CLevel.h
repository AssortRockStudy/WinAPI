#pragma once
// ������Ʈ�� ��� ���� Level Ŭ����
// ��� ����
// mVecObjects
// ������Ʈ �����ͷ� ���� �����̱� ������
// ������Ʈ Ŭ������ ��ӹ��� ��� ��ü�� ���� �� ����

class CObj;
class Monster;

class CLevel
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
	Monster* findCloseMon(Vec2 mPos);

public:
	CLevel();
	~CLevel();
};

