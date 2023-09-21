#pragma once

class CTexture;
class CSound;

class CAssetMgr
{
	SINGLETON(CAssetMgr);
private:
	map<wstring, CTexture*>	m_mapTex;
	map<wstring, CSound*>	m_mapSound;

public:
	CTexture* LoadTexture(const wstring& _strKey, const wstring& _strRelativePath);
	CTexture* FindTexture(const wstring& _strKey);
};