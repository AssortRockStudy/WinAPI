#pragma once

#define SINGLETON(ClassType)		public:\
										 static ClassType* GetInst()\
										{\
											static ClassType mgr;\
											return &mgr;\
										}\
										public:\
											ClassType* operator = (const ClassType& _Origin) = delete;\
										private:\
											ClassType();\
											ClassType(const ClassType& _Origin) = delete;\
											~ClassType();


// Key Manager
#define KEY_CHECK(Key,State) CKeyMgr::GetInst()->GetKeyState(Key) == State

#define KEY_TAP(Key) KEY_CHECK(Key, KEY_STATE::TAP)
#define KEY_PRESSED(Key) KEY_CHECK(Key, KEY_STATE::PRESSED)
#define KEY_RELEASED(Key) KEY_CHECK(Key, KEY_STATE::RELEASED)
#define KEY_NONE(Key) KEY_CHECK(Key, KEY_STATE::NONE)

#define PI 3.14159265348979f

