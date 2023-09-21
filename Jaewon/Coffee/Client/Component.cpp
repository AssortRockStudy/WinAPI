#include "pch.h"
#include "Component.h"
#include "CObj.h"

Component::Component(CObj* _owner):owner(_owner){}
Component::~Component(){}