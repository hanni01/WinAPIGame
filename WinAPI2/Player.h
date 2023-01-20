#pragma once
#include "GameObject.h"

class Player :
    public GameObject
{
public:
    Player();
    virtual ~Player() {};

    // GameObject을(를) 통해 상속됨
    virtual bool Awake() override;
    virtual void Start() override;
    virtual void Update() override;
    virtual void Render(HDC hdc) override;
    virtual void Release() override;

private:
    float mRadius = 50.0f;
};

