#pragma once
// ��ŸŸ���� ���� Ÿ�� �Ŵ��� ����
// � ������ PC���� �÷����ϴ��� ���� �ð����� ���� �Ÿ��� ������(�ð� ����ȭ)
// �Ŵ��� ��ü�� �̱������� ����
class CTimeMgr
{
	SINGLETON(CTimeMgr);

private:
	
	// union ��ü
	// ���� ū ũ�⸦ �����ϴ� ��ü
	// 8����Ʈ longlong Ÿ�� ������� �����ϸ� ��
	LARGE_INTEGER mFrequency; // �ʴ� �󵵼�
	LARGE_INTEGER mPrevCnt; // ���� ī��Ʈ
	LARGE_INTEGER mCurCnt; // ���� ī��Ʈ
	float mDeltaT;

public:
	float getDeltaTime() { return mDeltaT; }

public:
	void init();
	void tick();
};

