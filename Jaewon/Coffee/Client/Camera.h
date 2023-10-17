#pragma once
class Camera
{
	SINGLETON(Camera);
private:
	Vec2	mLookAt;
	Vec2	mDiff;

public:
	void tick();
	void SetLookAt(Vec2 _vLookAt) { mLookAt = _vLookAt; }
	Vec2 GetRenderPos(Vec2 _vRealPos) { return _vRealPos - mDiff; }
};

