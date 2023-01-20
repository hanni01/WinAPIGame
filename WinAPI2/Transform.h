#pragma once
#include "IComponent.h"
class Transform :
    public IComponent
{
public:
    // IComponent��(��) ���� ��ӵ�
    virtual void OnAlloc() override;
    virtual void OnFree() override;

    Position GetPosition() const; //const������ ��� ���� ���ٲ�
    void SetPosition(int x, int y);

private:
    Position mPos;
};

