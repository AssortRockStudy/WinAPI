#include "pch.h"
#include "Component.h"
#include "Obj.h"

Component::Component(Obj* _Owner)
	: m_pOwner(_Owner)
{
}

Component::~Component()
{
}
