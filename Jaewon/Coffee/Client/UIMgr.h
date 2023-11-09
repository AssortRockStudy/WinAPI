#pragma once

class UIMgr
{
	SINGLETON(UIMgr);
private:
	class UI* focusedUI;
public:
	void tick();

private:
	class UI* getPriorityChk(class UI* _parent);
};

