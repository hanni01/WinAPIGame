#pragma once
class IComponent
{
public:
	virtual void OnAlloc() = 0; // 할당 됐을 때
	virtual void OnFree() = 0; // 해제 될 때 호출
};

