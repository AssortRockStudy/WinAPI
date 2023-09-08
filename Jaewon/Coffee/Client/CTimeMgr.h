#pragma once
// 델타타임을 위한 타임 매니저 생성
// 어떤 성능의 PC에서 플레이하더라도 같은 시간에서 같은 거리를 가야함(시간 동기화)
// 매니저 객체는 싱글톤으로 구성
class CTimeMgr
{
	SINGLETON(CTimeMgr);

private:
	
	// union 객체
	// 가장 큰 크기를 공유하는 객체
	// 8바이트 longlong 타입 정수라고 생각하면 됨
	LARGE_INTEGER mFrequency; // 초당 빈도수
	LARGE_INTEGER mPrevCnt; // 이전 카운트
	LARGE_INTEGER mCurCnt; // 현재 카운트
	float mDeltaT;

public:
	float getDeltaTime() { return mDeltaT; }

public:
	void init();
	void tick();
};

