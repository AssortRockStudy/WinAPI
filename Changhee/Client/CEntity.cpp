#include "pch.h"
#include "CEntity.h"

UINT_PTR CEntity::g_NextID = 0;

CEntity::CEntity()
	: m_ID(g_NextID++)
{
}

CEntity::CEntity(const CEntity& _Other)
	: m_ID(g_NextID++)
{
}

CEntity::~CEntity()
{
}
