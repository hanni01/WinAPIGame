#include "pch.h"
#include "MainApp.h"
#include "Player.h"

#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif


bool MainApp::Intialize(HDC HDC)
{
	//초기화할 때 HDC 저장
	mHDC = HDC;

	if (mHDC == NULL)
	{
		return false;
	}
	//플레이어 생성
	mPlayer = new Player;
	if (mPlayer->Awake(mHDC) == false)
	{
		return false;
	}

	return true;
}

void MainApp::Update()
{
	mPlayer->Update();
}

void MainApp::Render()
{
	mPlayer->Render();
}

void MainApp::Release()
{
	mPlayer->Release();
	SAFE_DELETE(mPlayer); //동적 할당 해제
}
