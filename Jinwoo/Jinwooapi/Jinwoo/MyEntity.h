#pragma once

class MyEntity
{
private:
	static UINT_PTR g_NextID;

private:
	const UINT_PTR	m_ID;
	wstring			m_strName;
	bool			m_Dead;

public:
	UINT_PTR GetID() { return m_ID; }

	virtual MyEntity* Clone() { return nullptr; }

	void SetName(const wstring& _strName) {	m_strName = _strName; }
	const wstring& GetName() { return m_strName; }
	bool IsDead() { return m_Dead; }

public:
	MyEntity();
	MyEntity(const MyEntity& _Other);
	virtual ~MyEntity();

	friend class MyTaskMgr;
	friend class MyObject;
};

