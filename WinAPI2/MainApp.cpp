#include "pch.h"
#include "MainApp.h"
#include "Player.h"

#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif


bool MainApp::Intialize(HWND hWnd, HDC HDC, PAINTSTRUCT ps)
{
	//�ʱ�ȭ�� �� HDC ����
	mhWnd = hWnd;
	mHDC = HDC;
	mPS = ps;

	if (mHDC == NULL)
	{
		return false;
	}
	//�÷��̾� ����
	mPlayer = new Player;
	if (mPlayer->Awake() == false)
	{
		return false;
	}

	GetClientRect(mhWnd, &mRect);
	mhMemdc = CreateCompatibleDC(mHDC); // ȭ��dc(�׸� ������) ��� �޸� DC���� 
	HBITMAP hBitmap = CreateCompatibleBitmap(mHDC, mRect.right, mRect.bottom);

	// ���� ũ��� ������ ��Ʈ�� ����
	mhOldbitMap = (HBITMAP)SelectObject(mhMemdc, hBitmap); // ��Ʈ�� ����
	
	return true;
}

void MainApp::Update()
{
	mPlayer->Update();
}

void MainApp::Render()
{
	//��ȭ���� ���� �ֱ� (��� �ʱ�ȭ)
	FillRect(mhMemdc, &mRect, (HBRUSH)GetSysColor(COLOR_BACKGROUND)); // �޸� dc�� �׸���
	
	//������ ȭ�鿡 �׸��� (����)
	//������ HDC�� ��Ʈ�ʿ��ٰ�
	//������Ʈ �� �׸���/////////////////

	//LP = pointer
	//C = const
	//wstr = wchar_t
	//const wchar_t* text = L"Test";
	mPlayer->Render(mhMemdc);
	////////////////////////////////////

	BitBlt(mHDC, 0, 0, mRect.right, mRect.bottom, mhMemdc, 0, 0, SRCCOPY); // ��Ӻ��� hMemdc->hdc
}

void MainApp::Release()
{
	HBITMAP hBitMap = reinterpret_cast<HBITMAP>(SelectObject(mhMemdc, mhOldbitMap)); // ���� ��Ʈ������ �ٲ�ġ��
	DeleteObject(hBitMap);//������� ��Ʈ�� ����
	ReleaseDC(mhWnd, mHDC);//dc ����
	ReleaseDC(mhWnd, mhMemdc); // �޸� dc ����

	mPlayer->Release();
	SAFE_DELETE(mPlayer); //���� �Ҵ� ����
}
