#include "pch.h"
#include "MyEntity.h"

UINT_PTR MyEntity::g_NextID = 0;

// 가장 첫 ID를 0으로 주고 1을 더하기 위해 후위 연산자를 사용
MyEntity::MyEntity() : m_ID(g_NextID++)
{

}

// 복사를 했을 때 원본의 ID값을 그대로 가져오는 것을 방지
MyEntity::MyEntity(const MyEntity& _Other) : m_ID(g_NextID++)
{

}

MyEntity::~MyEntity()
{

}
