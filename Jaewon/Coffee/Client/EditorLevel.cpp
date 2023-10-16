#include "pch.h"
#include "EditorLevel.h"
#include "CEngine.h"
#include "Camera.h"

void EditorLevel::init()
{
}

void EditorLevel::enter()
{
	Vec2 vLookAt = CEngine::GetInst()->getMainResol();
	vLookAt /= 2.f;
	Camera::GetInst()->SetLookAt(vLookAt);

	createTile(10, 10);
}

void EditorLevel::exit()
{
	deleteAllObjects();
}

void EditorLevel::tick()
{
	CLevel::tick();
}
