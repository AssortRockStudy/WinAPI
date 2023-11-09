#pragma once

class Texture;
class Sound;


class AssetMgr
{
	SINGLETON(AssetMgr);

private: 
	map<wstring, Texture*> m_mapTex;
	map<wstring, Sound*> m_mapSound;

public:
	Texture* LoadTexture(const wstring& _strKey, const wstring& _strRelativePath);
	Texture* CreateTexture(const wstring& _strKey, UINT _width, UINT _height);
	Texture* FindTexture(const wstring& _strKey);

	Sound* LoadSound(const wstring& _strKey, const wstring& _strRelativePath);
	Sound* FindSound(const wstring& _strKey);
};

