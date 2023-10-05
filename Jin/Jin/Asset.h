#pragma once
#include "Entity.h"
class Asset :
    public Entity
{
private:
    wstring m_strKey;
    wstring m_strRelativePath;

    virtual bool Load(const wstring& _strFilePath) = 0;

public:
    Asset();
    ~Asset();
};

