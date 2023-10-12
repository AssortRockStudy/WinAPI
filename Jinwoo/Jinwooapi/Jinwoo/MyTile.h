#pragma once
#include "MyObject.h"

class MyTexture;

class MyTile :
    public MyObject
{
    GENERATED_OBJECT(MyObject);

private:
    MyTexture*  m_Atlas;
    int         m_Idx;

public:
    void SetAtlas(MyTexture* _Atlas) { m_Atlas = _Atlas; }
    void SetImageIdx(int _Idx) { m_Idx = _Idx; }

public:
    virtual void tick(float _DT) override;
    virtual void render(HDC _dc) override;

public:
    MyTile();
    ~MyTile();
};

