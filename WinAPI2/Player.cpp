#include "pch.h"
#include "Player.h"

extern HWND hWnd; //진정한 global변수

Player::Player()
{
}

bool Player::Awake(HDC HDC, PAINTSTRUCT ps)
{
	mHDC = HDC;
	mPS = ps;
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
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		mPos.x += 10.0f;
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		mPos.x -= 10.0f;
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		mPos.y -= 10.0f;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		mPos.y += 10.0f;
	}
	InvalidateRect(hWnd, NULL, TRUE); //지속적인 화면 표시를 위함. 특정 영역을 업데이트(다시 그리는) 함수
	//(hWnd, *IpRect, bErase): *IpRect는 업데이트할 영역 설정
	//bErase는 영역안 배경이 업데이트 될때 제거 될 것인지 여부
	//BeginPaint함수가 호출될 때 배경이 제거된다.
	system("cls");//버퍼링이 사라짐 

}

void Player::Render()
{
	mHDC = BeginPaint(hWnd, &mPS);
	Ellipse(mHDC, mPos.x - mRadius, mPos.y - mRadius, mPos.x + mRadius, mPos.y + mRadius);
	EndPaint(hWnd, &mPS);
	cout << "Player Render Success" << endl;
}

void Player::Release()
{

}