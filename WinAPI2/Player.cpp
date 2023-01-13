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
}

void Player::Render()
{
	Ellipse(mHDC, mPos.x - mRadius, mPos.y - mRadius, mPos.x + mRadius, mPos.y + mRadius);
	cout << "Player Render Success" << endl;
}

void Player::Release()
{

}
