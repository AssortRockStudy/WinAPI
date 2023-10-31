#pragma once
class CUI;

class CUIMgr
{
	SINGLETON(CUIMgr);
public:
	void tick();
private:
	CUI* GetPriorityCheck(CUI* _ParentUI);
};

