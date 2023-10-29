#include "pch.h"
#include "CEditorLevel.h"

void CEditorLevel::init()
{
}


void CEditorLevel::enter()
{
	CreateTile(1, 1);
}

void CEditorLevel::exit()
{
	DeleteAllObjects();
}

void CEditorLevel::tick()
{
	CLevel::tick();


}