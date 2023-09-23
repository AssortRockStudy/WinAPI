#pragma once
#include "CEntity.h"
#include "TaskMgr.h"
#include "Camera.h"
#include "Collider.h"

class Component;
class Collider;

class CObj:public CEntity
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

private:
	void setDead();

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
	void Destroy();
	virtual void beginOverLap(Collider* mycol, CObj* _othObj, Collider* _othCol){}
	virtual void overLap(Collider* mycol, CObj* _othObj, Collider* _othCol){}
	virtual void endOverLap(Collider* mycol, CObj* _othObj, Collider* _othCol) {}


public:
	CObj();
	virtual ~CObj();

	friend class CLevel;
	friend class TaskMgr;
};

