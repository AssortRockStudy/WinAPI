#pragma once
#include "CObj.h"
class Tile :
    public CObj
{
    GENERATED_OBJECT(CObj);
private:
    class CTexture* atlas;
    int idx;

public:
    void setAtlas(CTexture* _Atlas) { atlas = _Atlas; }
    void setImgIdx(int _ImgIdx) { idx = _ImgIdx; }
    void addImgIdx();

public:
    virtual void tick(float _DT) override;
    virtual void render(HDC _dc) override;

public:
    Tile();
    ~Tile();
};

