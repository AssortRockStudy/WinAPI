#pragma once


class CLogMgr
{
	SINGLETON(CLogMgr)
private:
	list<FLog>	m_LogList;

	float		m_LogMaxLife;

public:
	void SetLogMaxLife(float _Life) { m_LogMaxLife = _Life; }

	void AddLog(const FLog& _log) { m_LogList.push_front(_log); }

public:
	void tick(HDC _dc);
};

