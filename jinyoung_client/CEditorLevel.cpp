#include "pch.h"
#include "CEditorLevel.h"

#include "CKeyman.h"

#include "CEngine.h"
#include "CCamera.h"

#include "Resource.h"

void CEditorLevel::init()
{
}


void CEditorLevel::enter()
{
	// �޴��� ����
// ���ҽ� ���̵�� �޴��� ��� ����
	HMENU hMenu = LoadMenu(nullptr, MAKEINTRESOURCE(IDC_JINYOUNGCLIENT));

	// ���� �����쿡 ������Ų �޴��� ���̱�
	SetMenu(CEngine::GetInst()->GetMainWind(), hMenu);

	// �޴��� �߰��Ǿ��� ������ ������ ũ�⸦ ������
	POINT ptResSol = CEngine::GetInst()->GetResolution();
	CEngine::GetInst()->ChangeWindowSize(ptResSol, true);

	// ī�޶� ����
	Vec2 vLookAt = CEngine::GetInst()->GetResolution();
	vLookAt /= 2.f;
	CCamera::GetInst()->SetLookAt(vLookAt);

	// Ÿ�� ����
	CreateTile(10, 10);
}

void CEditorLevel::exit()
{
	DeleteAllObjects();

	// �޴��� ����
// ���� �����쿡 �پ��ִ� �޴��� �ڵ�(���̵�) �� �˾Ƴ���.
	HMENU hMenu = GetMenu(CEngine::GetInst()->GetMainWind());

	// ���� �����쿡 �����Ǿ��ִ� �޴��� �����.
	SetMenu(CEngine::GetInst()->GetMainWind(), nullptr);

	// �޴��� �޸� ������Ų��.
	DestroyMenu(hMenu);

	// �޴��� �����쿡�� ����������, ������ ũ�⸦ �ٽ� �������ش�.
	POINT ptResSol = CEngine::GetInst()->GetResolution();
	CEngine::GetInst()->ChangeWindowSize(ptResSol, false);
}

void CEditorLevel::tick()
{
	CLevel::tick();

	// Enter Ű�� ������ StartLevel �� ��ȯ
	if (KEY_TAP(KEY::ENTER))
	{
		ChangeLevel(LEVEL_TYPE::PLAY_LEVEL);
	}

}