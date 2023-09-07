#pragma once
// 첫번째 호출시 객체 생성
// 이후로는 해당 주소 반환
#define SINGLETON(ClassType) public:\
								static ClassType* GetInst() {\
									static ClassType inst;\
									return &inst;\
								}\
								public:\
									ClassType* operator = (const ClassType& _Origin) = delete;\
								private:\
									ClassType();\
									ClassType(const ClassType& _Origin) = delete;\
									~ClassType();