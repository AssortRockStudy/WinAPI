#include "pch.h"
#include "LogMgr.h"
#include "TimeMgr.h"

LogMgr::LogMgr()
	: m_LogMaxLife(5.f)
{
}

LogMgr::~LogMgr()
{
}

void LogMgr::tick(HDC _dc)
{
	list<FLog>::iterator iter = m_LogList.begin();

	for (; iter != m_LogList.end(); )
	{
		(*iter).AccTime += DT;
		if (m_LogMaxLife < (*iter).AccTime)
		{
			iter = m_LogList.erase(iter);
		}
		else
		{
			++iter;
		}
	}

	iter = m_LogList.begin();
	POINT LT = { 10, 10 };

	int i = 0;
	for (; iter != m_LogList.end(); ++iter, ++i)
	{
		switch ((*iter).Level)
		{
		case LOG:
			SetTextColor(_dc, RGB(0, 0, 0));
			TextOut(_dc, LT.x, LT.y + i * int(10.f * 1.5f), (*iter).Message.c_str(), (*iter).Message.length());
			break;
		case WARNING:
			SetTextColor(_dc, RGB(210, 210, 153));
			break;
		case ERR:
			SetTextColor(_dc, RGB(255, 0, 0));
			break;
		}

		TextOut(_dc, LT.x, LT.y + i * int(10.f * 1.5f), (*iter).Message.c_str(), (*iter).Message.length());
	}
}
