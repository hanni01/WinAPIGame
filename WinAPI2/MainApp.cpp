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
	//�ʱ�ȭ�� �� HDC ����
	mHDC = HDC;

	if (mHDC == NULL)
	{
		return false;
	}
	//�÷��̾� ����
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
	SAFE_DELETE(mPlayer); //���� �Ҵ� ����
}
