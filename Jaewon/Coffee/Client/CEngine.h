#pragma once

// �̱��� �������� ����
// ������ �� �ϳ��� �����Ǿ�� ��
// 1. �ܺο��� ��ü ������ �������� �����ڸ� private
// 2. ���� ��� ������ ��ü�� ����, cpp�� �ʱ�ȭ (���� ����� ����)
// 3. ���� ��� �Լ� GetInst() : ���� ��� �Լ��� �ܺο� �̱��� ��ü�� �ּҸ� �ִ� �Լ�
// 4. ���� ������ �ļ��� ��ü�� ������ �� �����Ƿ� ���ƾ� �Ѵ�.
class CEngine
{
private:
	static CEngine* g_inst; 

public:

	// ���� ����Լ��� ��ü�� ��� ȣ��� �� ����
	// this�� ����
	static CEngine* GetInst() {
		if (nullptr == g_inst) {
			g_inst = new CEngine;
		}
		return g_inst;
	}
	void Destroy() {
		delete g_inst;
		g_inst = nullptr;
	}
	
public:
	// ���� ������ ����
	// 2���� ��ü�� ������ ���� ���� ������ ������ �־�� �Ѵ�.
	CEngine* operator = (const CEngine& _Origin) = delete;

private:
	CEngine();
	// ���� ������ ����
	// �ϳ����� �����ϹǷ� ��������ڸ� ������ �־�� �Ѵ�.
	CEngine(const CEngine& _Origin) = delete;

public:
	~CEngine();
};

