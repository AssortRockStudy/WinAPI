#pragma once
class MyCameraMgr
{
	SINGLETON(MyCameraMgr);

private:
	Vec2 m_LookAt;
	Vec2 m_CameraMove;

public:
	void tick();
	void SetLookAt(Vec2 _LookAt) { m_LookAt = _LookAt; }

	Vec2 GetRenderPos(Vec2 _RealPos)
	{
		return _RealPos - m_CameraMove;
	}
};

