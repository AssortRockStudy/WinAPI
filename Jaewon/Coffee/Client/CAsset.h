#pragma once
#include "CEntity.h"
class CAsset :
    public CEntity
{
private:
    wstring sKey;
    wstring sPath;

private:
    virtual bool load(const wstring& _sPath) = 0;

public:
    CAsset();
    ~CAsset();
};

