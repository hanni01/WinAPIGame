#pragma once
#include "GameObject.h"

class Bullet :
    public GameObject
{
public:
    virtual bool Awake() override;
    virtual void Start() override;
    virtual void Update() override;
    virtual void Render(HDC hdc) override;
    virtual void Release() override;
};

