#include "pch.h"
#include "EditorLevel.h"

#include "Engine.h"
#include "Camera.h"

void EditorLevel::init()
{
}

void EditorLevel::enter()
{
	Vec2 vLookAt = Engine::GetInst()->GetResolution();
	vLookAt /= 2.f;
	Camera::GetInst()->SetLookAt(vLookAt);

	CreateTile(10, 10);
}

void EditorLevel::exit()
{
	DeleteAllObjects();
}

void EditorLevel::tick()
{
	Level::tick();
}
