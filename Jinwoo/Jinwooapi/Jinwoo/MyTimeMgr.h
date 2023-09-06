#pragma once

class MyTimeMgr
{
	SINGLETON(MyTimeMgr);

private:
	// LARGE_INTEGER�� �׳� 8����Ʈ long long ���
	LARGE_INTEGER	m_Frequency;
	LARGE_INTEGER	m_PrevCount;
	LARGE_INTEGER	m_CurCount;

	// ��ŸŸ�� = ���� �����Ӱ� ���� �������� �ð��� ����
	float			m_DeltaTime;

public:
	float GetDeltaTime() { return m_DeltaTime; }

public:
	void init();
	void tick();
};

