#include "pch.h"
#include "define.h"
#include "Monster.h"

#include "KeyMgr.h"
#include "TimeMgr.h"
#include "DrawMgr.h"

Monster::Monster()
	: m_Info{}
{
}

Monster::~Monster()
{
}


void Monster::tick(float _DT)
{
	Super::tick(_DT);
}

