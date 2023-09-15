#include "pch.h"
#include "MyComponent.h"

#include "MyObject.h"

MyComponent::MyComponent(MyObject* _Object) : m_pOwner(_Object)
{
}

MyComponent::~MyComponent()
{
}