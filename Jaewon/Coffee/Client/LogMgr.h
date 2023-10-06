#pragma once
class LogMgr{
	SINGLETON(LogMgr)
private:
	list<FLog>	mLogList;
	float		mLogMaxLife;

public:
	void SetLogMaxLife(float _life) { mLogMaxLife = _life; }

	void AddLog(const FLog& _log) { mLogList.push_front(_log); }

public:
	void tick(HDC _dc);
};

#define LOG(Level, Message)		{\
									string funcname = __FUNCTION__; \
									wchar_t szBuffer[100] = {};\
									swprintf_s(szBuffer, L"Function : %s  {Line : %d } : %s"\
										, wstring(funcname.begin(), funcname.end()).c_str(), __LINE__\
										, Message);\
									LogMgr::GetInst()->AddLog(FLog{ Level, szBuffer });\
								}