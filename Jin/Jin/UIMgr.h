#pragma once
class UI;

class UIMgr
{
	SINGLETON(UIMgr);

private:
	UI* m_FocusedUI;

public:
	void tick();

private:
	UI* GetPriorityCheck(UI* _ParentUI);
};

