#pragma once
class UI;

class UIMgr
{
	SINGLETON(UIMgr);

public:
	void tick();

private:
	UI* GetPriorityCheck(UI* _ParentUI);
};

