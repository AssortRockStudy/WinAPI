#pragma once

#include "Asset.h"

class Sound
	: public Asset
{

public:
	virtual bool Load(const wstring& _strFilePath) override;
};
