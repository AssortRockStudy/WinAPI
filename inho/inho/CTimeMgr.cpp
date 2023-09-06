#include "CTimeMgr.h"
#include "pch.h"

// ���� ū �ڷ��� �������� ���� ������ ��Ī�ϴ� DataType ���� ���
union MousePos {
    struct {
        short High;
        short Low;
    };

    UINT value;
};

CTimeMgr::CTimeMgr() : m_Frequency{}, m_PrevCount{}, m_CurCount{} {}

CTimeMgr::~CTimeMgr() {}

void CTimeMgr::init() {
    // �ʴ� ��
    QueryPerformanceFrequency(&m_Frequency);

    QueryPerformanceCounter(&m_PrevCount);
}

void CTimeMgr::tick() {
    QueryPerformanceCounter(&m_CurCount);

    m_DeltaTime = float(m_CurCount.QuadPart - m_PrevCount.QuadPart) /
                  float(m_Frequency.QuadPart);

    m_PrevCount = m_CurCount;
}