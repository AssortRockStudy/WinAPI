#pragma once
#include "MyEntity.h"


class MyAsset : public MyEntity
{
private:
	wstring		m_strKey;
	wstring		m_strRelativePath;

private:
	virtual bool Load(const wstring& _strFilePath) = 0;

public:
	MyAsset();
	~MyAsset();
};

