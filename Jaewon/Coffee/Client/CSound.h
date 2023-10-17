#pragma once
#include "CAsset.h"
class CSound :
    public CAsset
{
public:
    virtual bool load(const wstring& _strFilePath) override;
};

