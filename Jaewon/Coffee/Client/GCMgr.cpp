#include "pch.h"
#include "GCMgr.h"

void GCMgr::tick()
{
	if (mEntity.size() < 10)
		return;
	for (size_t i = 0; i < mEntity.size(); ++i) {
		if (nullptr != mEntity[i])
			delete mEntity[i];
	}
	mEntity.clear();
}

GCMgr::GCMgr()
{

}

GCMgr::~GCMgr()
{
	for (size_t i = 0; i < mEntity.size(); ++i){
		if (nullptr != mEntity[i])
			delete mEntity[i];
	}
}
