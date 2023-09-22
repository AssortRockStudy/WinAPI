#pragma once

class MyTexture;
class MySound;

class MyAssetMgr
{
	SINGLETON(MyAssetMgr);

private:
	map<wstring, MyTexture*>	m_mapTex;
	map<wstring, MySound*>		m_mapSound;

public:
	MyTexture* LoadTexture(const wstring& _strKey, const wstring& _strRelativePath);
	MyTexture* FindTexture(const wstring& _strKey);
};

