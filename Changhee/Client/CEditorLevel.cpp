#include "pch.h"
#include "CEditorLevel.h"

#include "CEngine.h"
#include "CCamera.h"

void CEditorLevel::init()
{
}

void CEditorLevel::enter()
{
	// 카메라 설정
	Vec2 vLookAt = CEngine::GetInst()->GetResolution();
	vLookAt /= 2.f;
	CCamera::GetInst()->SetLookAt(vLookAt);

	// 타일 생성
	CreateTile(10, 10);
}

void CEditorLevel::exit()
{
}

void CEditorLevel::tick()
{
	CLevel::tick();
}
