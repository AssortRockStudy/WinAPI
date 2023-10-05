#include "pch.h"
#include "GCMgr.h"

GCMgr::GCMgr()
{

}

GCMgr::~GCMgr()
{
	for (size_t i = 0; i < m_Entity.size(); ++i)
	{
		if (nullptr != m_Entity[i])
		{
			delete m_Entity[i];
		}
	}
}

void GCMgr::tick()
{
	if (m_Entity.size() < 10)
	{
		return;
	}
	for (size_t i = 0; i < m_Entity.size(); ++i)
	{
		if (nullptr != m_Entity[i])
		{
			delete m_Entity[i];
		}
	}
	m_Entity.clear();
}
