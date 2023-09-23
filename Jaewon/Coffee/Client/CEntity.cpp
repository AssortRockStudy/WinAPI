#include "pch.h"
#include "CEntity.h"

UINT_PTR CEntity::next_id = 0;

CEntity::CEntity():mID(next_id++), mDead(false)
{
}

CEntity::CEntity(const CEntity& _oth) :mID(next_id++), mDead(false)
{
}

CEntity::~CEntity()
{
}
