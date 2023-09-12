#pragma once
class DrawMgr
{
	SINGLETON(DrawMgr);

public:
	vector<HPEN> pens;
	vector<HBRUSH> brushes;

public:
	void init();
	void tick();
};

