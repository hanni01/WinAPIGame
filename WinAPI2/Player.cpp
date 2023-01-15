#include "pch.h"
#include "Player.h"

Player::Player()
{
}

bool Player::Awake(HDC HDC)
{
	mHDC = HDC;
	mPos.x = 100;
	mPos.y = 100;
	cout << "Player Awake Success" << endl;
	return true;
}

void Player::Start()
{
}

void Player::Update()
{
	cout << "Player Update Success" << endl;
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) mPos.x += 5.0f;
	if (GetAsyncKeyState(VK_LEFT) & 0x8000) mPos.x -= 5.0f;
	if (GetAsyncKeyState(VK_UP) & 0x8000) mPos.y -= 5.0f;
	if (GetAsyncKeyState(VK_DOWN) & 0x8000) mPos.y += 5.0f;
	system("cls");//버퍼링이 사라짐 

}

void Player::Render()
{
	Ellipse(mHDC, mPos.x - mRadius, mPos.y - mRadius, mPos.x + mRadius, mPos.y + mRadius);
	cout << "Player Render Success" << endl;
}

void Player::Release()
{

}
