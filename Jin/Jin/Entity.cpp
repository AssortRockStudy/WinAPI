#include "pch.h"
#include "Entity.h"

UINT_PTR Entity::g_NextID = 0;


Entity::Entity()
	:m_ID(g_NextID++)
{
}

Entity::Entity(const Entity& _other)
	: m_ID(g_NextID++)
{
}

Entity::~Entity()
{
}
