#pragma once
class GameObject //abstract - > 추상 함수 생성시 자동으로 추상적으로 됨//제한 걸어주기 얘로는 객체를 생성할 수 없다
{
public:
	GameObject();
	virtual ~GameObject() {};

	virtual bool Awake(HDC HDC) = 0; //추상 함수
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Release() = 0;

protected:
	HDC mHDC;
	Position mPos;
};

