#pragma once
#include "MyAsset.h"
class MySound :
    public MyAsset
{
private:
    virtual bool Load(const wstring& _strFilePath) override;

public:
    MySound();
    ~MySound();

    friend class MyAssetMgr;
};

