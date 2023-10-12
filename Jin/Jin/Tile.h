#pragma once
#include "Obj.h"
class Tile :
    public Obj
{
    GENERATED_OBJECT(Tile);

private: 
    class Texture* m_Atlas;
    int m_Idx;

public:
    void SetAtlas(Texture* _Atlas) 
    { 
        m_Atlas = _Atlas; 
    }
    void SetImgIdx(int _ImgIdx) 
    {
        m_Idx = _ImgIdx; 
    }
    virtual void tick(float _DT) override;
    virtual void render(HDC _dc) override;



public:
    Tile();
    ~Tile();
};

