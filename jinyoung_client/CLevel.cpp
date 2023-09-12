﻿#include "pch.h"
#include "CLevel.h"

#include "CTimeManager.h"
#include "CObj.h"



CLevel::CLevel()
{

}

CLevel::~CLevel()
{

}

void CLevel::tick()
{
	//float DT = CTimeManager::GetInst()->GetDeltaTime();

	for (size_t i = 0; i < m_vecObjects.size(); ++i)
	{
		m_vecObjects[i]->tick(DT);
	}
}

void CLevel::render(HDC _dc)
{
	for (size_t i = 0; i < m_vecObjects.size(); ++i)
	{
		m_vecObjects[i]->render(_dc);
	}
}
