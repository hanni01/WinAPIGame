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
	//초기화할 때 HDC 저장
	mhWnd = hWnd;
	mHDC = HDC;
	mPS = ps;

	if (mHDC == NULL)
	{
		return false;
	}
	//플레이어 생성
	mPlayer = new Player;
	if (mPlayer->Awake() == false)
	{
		return false;
	}

	GetClientRect(mhWnd, &mRect);
	mhMemdc = CreateCompatibleDC(mHDC); // 화면dc(그릴 윈도우) 기반 메모리 DC생성 
	HBITMAP hBitmap = CreateCompatibleBitmap(mHDC, mRect.right, mRect.bottom);

	// 현재 크기와 동일한 비트맵 생성
	mhOldbitMap = (HBITMAP)SelectObject(mhMemdc, hBitmap); // 비트맵 선택
	
	return true;
}

void MainApp::Update()
{
	mPlayer->Update();
}

void MainApp::Render()
{
	//도화지에 색상 넣기 (배경 초기화)
	FillRect(mhMemdc, &mRect, (HBRUSH)GetSysColor(COLOR_BACKGROUND)); // 메모리 dc에 그리기
	
	//실제로 화면에 그리는 (복사)
	//복사한 HDC의 비트맵에다가
	//오브젝트 다 그리기/////////////////

	//LP = pointer
	//C = const
	//wstr = wchar_t
	//const wchar_t* text = L"Test";
	mPlayer->Render(mhMemdc);
	////////////////////////////////////

	BitBlt(mHDC, 0, 0, mRect.right, mRect.bottom, mhMemdc, 0, 0, SRCCOPY); // 고속복사 hMemdc->hdc
}

void MainApp::Release()
{
	HBITMAP hBitMap = reinterpret_cast<HBITMAP>(SelectObject(mhMemdc, mhOldbitMap)); // 기존 비트맵으로 바꿔치기
	DeleteObject(hBitMap);//만들었던 비트맵 해제
	ReleaseDC(mhWnd, mHDC);//dc 해제
	ReleaseDC(mhWnd, mhMemdc); // 메모리 dc 해제

	mPlayer->Release();
	SAFE_DELETE(mPlayer); //동적 할당 해제
}
