#include "pch.h"
#include "MyTimeMgr.h"

MyTimeMgr::MyTimeMgr() : m_Frequency{}, m_PrevCount{}, m_CurCount{}
{

}

MyTimeMgr::~MyTimeMgr()
{

}

void MyTimeMgr::init()
{
	// ���� ī������ �󵵸� �˻��Ѵ�(�ش� Ÿ�̸Ӱ� �ʴ� �� ���� �ֱ⸦ �Ϸ��ϴ°�)
	// ���ڷ� LARGE_INTEGER ����ü ������ �����͸� ������
	QueryPerformanceFrequency(&m_Frequency);

	// �ð� ���� ����
	QueryPerformanceCounter(&m_PrevCount);
}

void MyTimeMgr::tick()
{
	QueryPerformanceCounter(&m_CurCount);

	// ��ǻ���� ���ɰ� ������� 1�ʵ��� ������ �۾��� �ؾ��Ѵ�
	m_DeltaTime = float(m_CurCount.QuadPart - m_PrevCount.QuadPart) / float(m_Frequency.QuadPart);

	m_PrevCount = m_CurCount;
}
