#pragma once

class CEntity
{
private:
	static UINT_PTR g_NextID;

private:
	const UINT_PTR	m_ID;

public:
	UINT_PTR GetID() { return m_ID; }


public:
	virtual CEntity* Clone() { return nullptr; }

public:
	CEntity();
	CEntity(const CEntity& _Other);
	virtual ~CEntity();

};

