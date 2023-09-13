#pragma once
class CEntity
{

private:
	static UINT_PTR g_NextID;
	const UINT_PTR m_ID;

public:
	__inline UINT_PTR GetID() { return m_ID; }
	virtual CEntity* Clone() { return nullptr; };

	CEntity();
	CEntity(const CEntity& _other);
	//CEntity& operator = (const CEntity& _other);
	virtual ~CEntity();

};

