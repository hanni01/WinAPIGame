#pragma once
class IComponent
{
public:
	virtual void OnAlloc() = 0; // �Ҵ� ���� ��
	virtual void OnFree() = 0; // ���� �� �� ȣ��
};

