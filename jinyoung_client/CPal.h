#pragma once
#include "pch.h"





class CPal
{
	//�̱��������� : �귯���� ���ӿ��� �׻󾲱⶧��
	SINGLETON(CPal);



private:
	vector<HPEN> vhp;
	vector<HBRUSH> vhb;


public:
	HPEN getHPen(COLOR _COLOR);
	HBRUSH getHBrush(COLOR _COLOR);
};

