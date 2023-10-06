#include "pch.h"
#include "LogMgr.h"
#include "CTimeMgr.h"

void LogMgr::tick(HDC _dc)
{
	float DT = CTimeMgr::GetInst()->getDeltaTime();
	list<FLog>::iterator iter = mLogList.begin();

	for (; iter != mLogList.end(); )
	{
		(*iter).AccTime += DT;
		if (mLogMaxLife < (*iter).AccTime)
			iter = mLogList.erase(iter);
		else
			++iter;
	}

	iter = mLogList.begin();
	POINT LT = { 10, 10 };

	int i = 0;
	for (; iter != mLogList.end(); ++iter, ++i){
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

LogMgr::LogMgr():mLogMaxLife(5.f){}
LogMgr::~LogMgr(){}