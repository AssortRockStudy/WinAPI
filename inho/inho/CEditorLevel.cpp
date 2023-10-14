#include "pch.h"
#include "CEditorLevel.h"

#include "CEngine.h"
#include "CCamera.h"

void CEditorLevel::init()
{
}

void CEditorLevel::enter()
{
	Vec2 vLookAt = CEngine::GetInst()->GetResolution();
	vLookAt /= 2.f;
	CCamera::GetInst()->SetLookAt(vLookAt);

	CreateTile(10, 10);
}

void CEditorLevel::exit()
{
	DeleteAllObjects();
}

void CEditorLevel::tick()
{
	CLevel::tick();
}
