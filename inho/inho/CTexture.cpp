﻿#include "pch.h"

#include "CTexture.h"

#include "CEngine.h"

CTexture::CTexture():
	m_hBit(nullptr),
	m_hDC(nullptr),
	m_Info{}
{}

CTexture::~CTexture() {

	DeleteObject(m_hBit);
	DeleteDC(m_hDC);
}

bool CTexture::Load(const wstring& _strFilePath) {
	m_hBit = (HBITMAP)LoadImage(nullptr, _strFilePath.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	if (nullptr == m_hBit) {
		return false;
	}

	m_hDC = CreateCompatibleDC(CEngine::GetInst()->GetMainDC());
	DeleteObject(SelectObject(m_hDC, m_hBit));
	GetObject(m_hBit, sizeof(BITMAP), &m_Info);

	return true;

}