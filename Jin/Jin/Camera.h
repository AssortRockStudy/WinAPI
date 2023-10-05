#pragma once
class Camera
{
	SINGLETON(Camera);

private:
	Vec2 m_vLookAt;
	Vec2 m_vDiff;

public:
	void tick();
	void SetLookAt(Vec2 _vLookAt)
	{
		m_vLookAt = _vLookAt;
	}
	Vec2 GetRenderPos(Vec2 _vRealPos)
	{
		return _vRealPos - m_vDiff;
	}
};

