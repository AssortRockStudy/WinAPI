#pragma once
// ��� ��ü���� �θ� Ŭ����
// ��ü�鿡�� id�� �ο�
// Entity ������ ����� �ߺ� id�� ���� ���� ���� ������ �����ε�
class CEntity
{
private:
	static UINT_PTR next_id;

private:
	const UINT_PTR mID;

public: 
	UINT_PTR getID() { return mID; }

public:
	virtual CEntity* Clone() { return nullptr; } // ���߿� �����ҵ�?

public:
	CEntity();
	CEntity(const CEntity& _oth);
	virtual ~CEntity();
};

