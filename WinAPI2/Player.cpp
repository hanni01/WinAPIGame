#include "pch.h"
#include "Player.h"

extern HWND hWnd; //������ global����

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
	InvalidateRect(hWnd, NULL, TRUE); //�������� ȭ�� ǥ�ø� ����. Ư�� ������ ������Ʈ(�ٽ� �׸���) �Լ�
	//(hWnd, *IpRect, bErase): *IpRect�� ������Ʈ�� ���� ����
	//bErase�� ������ ����� ������Ʈ �ɶ� ���� �� ������ ����
	//BeginPaint�Լ��� ȣ��� �� ����� ���ŵȴ�.
	system("cls");//���۸��� ����� 

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