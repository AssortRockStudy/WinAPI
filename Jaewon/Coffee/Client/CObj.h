#pragma once
#include "CEntity.h"
#include "TaskMgr.h"
#include "Camera.h"

class Component;

class CObj
{
private:
	virtual void Abstract() = 0;
private:
	
	Vec2 mPos;
	Vec2 mScale;
	int mLayerIdx;
	vector<Component*> mVecComponent;

public:
	Vec2 getPos() { return mPos; }
	Vec2 getRenderPos() { return Camera::GetInst()->GetRenderPos(mPos); }
	Vec2 getScale() { return mScale; }
	int getLayerIdx() { return mLayerIdx; }

	void setPos(Vec2 _pos) { mPos = _pos; }
	void setScale(Vec2 _scale) { mScale = _scale; }

protected:
	template<typename T>
	T* addComponent(const wstring& _strname = L"") {
		T* newCom = new T(this);
		mVecComponent.push_back(newCom);
		newCom->setName(_strname);
		return newCom;
	}

public:
	virtual void begin() {};
	virtual void tick(float _dt);
	virtual void finalTick(float _dt) final;
	virtual void render(HDC _dc);


public:
	CObj();
	virtual ~CObj();

	friend class CLevel;
	friend class TaskMgr;
};

