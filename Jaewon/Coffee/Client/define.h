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

#define CREATEBLACKPEN CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
#define CREATEREDPEN CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
#define CREATEBLACKBRUSH CreateSolidBrush(RGB(0, 0, 0));
#define CREATEREDBRUSH CreateSolidBrush(RGB(255, 0, 0));

enum COLOR {
	red,
	blue,
	green,
	black,
};