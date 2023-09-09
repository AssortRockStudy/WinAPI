#include "pch.h"

#include "CTimeMgr.h"


#include "CEngine.h"

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

    m_fTime += m_DeltaTime;
    if (1.f <= m_fTime) {
        wchar_t szText[50] = {};
        swprintf_s(szText, 50, L"FPS [%d]", m_iCall);
        SetWindowText(CEngine::GetInst()->GetMainWind(), szText);

        m_iCall = 0;
        m_fTime = 0;
    }

    ++m_iCall;

 
}