#pragma once
#include "IComponent.h"
class Transform :
    public IComponent
{
public:
    // IComponent을(를) 통해 상속됨
    virtual void OnAlloc() override;
    virtual void OnFree() override;

    Position GetPosition() const; //const붙으면 멤버 변수 못바꿈
    void SetPosition(int x, int y);

private:
    Position mPos;
};

