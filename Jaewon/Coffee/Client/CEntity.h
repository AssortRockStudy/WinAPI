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
	wstring strName;

public: 
	UINT_PTR getID() { return mID; }
	const wstring& getName() { return strName; }
	void setName(const wstring& _strname) { strName = _strname; }


public:
	virtual CEntity* Clone() { return nullptr; } // ���߿� �����ҵ�?

public:
	CEntity();
	CEntity(const CEntity& _oth);
	virtual ~CEntity();
};

