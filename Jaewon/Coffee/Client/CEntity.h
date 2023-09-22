#pragma once
// 모든 객체들의 부모 클래스
// 객체들에게 id를 부여
// Entity 끼리의 복사는 중복 id를 막기 이해 복사 생성자 오버로딩
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
	virtual CEntity* Clone() { return nullptr; } // 나중에 변경할듯?

public:
	CEntity();
	CEntity(const CEntity& _oth);
	virtual ~CEntity();
};

