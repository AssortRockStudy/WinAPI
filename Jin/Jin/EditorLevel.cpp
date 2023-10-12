#include "pch.h"
#include "EditorLevel.h"

void EditorLevel::init()
{
}

void EditorLevel::enter()
{
	CreateTile(1, 1);
}

void EditorLevel::exit()
{
	DeleteAllObjects();
}

void EditorLevel::tick()
{
	Level::tick();
}
