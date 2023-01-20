#include "pch.h"
#include "Player.h"
#include "Transform.h"

extern HWND hWnd; //진정한 global변수

Player::Player()
{
}

bool Player::Awake()
{
	Transform* transform = GetComponent<Transform>();
	transform->SetPosition(100, 100);

	cout << "Player Awake Success" << endl;
	return true;
}

void Player::Start()
{
}

void Player::Update()
{
	cout << "Player Update Success" << endl;
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		//mPos.x += 10.0f;
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		//mPos.x -= 10.0f;
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		//mPos.y -= 10.0f;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		//mPos.y += 10.0f;
	}

}

void Player::Render(HDC hdc)
{
	//hdc = BeginPaint(hWnd, &mPS);
	Transform* transform = GetComponent<Transform>();
	if (transform == nullptr)
	{
		return;
	}

	Position position = transform->GetPosition();
	Ellipse(hdc, position.x - mRadius, position.y - mRadius, position.x + mRadius, position.y + mRadius);
	//EndPaint(hWnd, &mPS);
	cout << "Player Render Success" << endl;
}

void Player::Release()
{

}