#pragma once
class DrawMgr
{
	SINGLETON(DrawMgr);

	vector<HPEN> pens;
	vector<HBRUSH> brushes;

public:
	void init();
	void tick();
};

