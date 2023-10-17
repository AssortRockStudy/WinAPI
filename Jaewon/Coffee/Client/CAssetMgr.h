#pragma once

class CTexture;
class CSound;

class CAssetMgr
{
	SINGLETON(CAssetMgr);

private:
	map<wstring, CTexture*>	mTexture;
	map<wstring, CSound*>	mSound;

public:
	CTexture* LoadTexture(const wstring& _strKey, const wstring& _strRelativePath);
	CTexture* FindTexture(const wstring& _strKey);
};

