#pragma once
#include "GameObject.h"

class Player :
    public GameObject
{
public:
    Player();
    virtual ~Player() {};

    // GameObject��(��) ���� ��ӵ�
    virtual bool Awake(HDC HDC) override;
    virtual void Start() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;

private:
    float mRadius = 5.0f;
};

