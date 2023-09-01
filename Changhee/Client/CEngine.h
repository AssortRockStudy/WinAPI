#pragma once


class CEngine
{
private:

public:
	static CEngine* GetInst()
	{
		static CEngine myEngine;

		return &myEngine;
	}


private:
	CEngine();

public:
	~CEngine();
};

