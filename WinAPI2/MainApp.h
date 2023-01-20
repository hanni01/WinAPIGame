#pragma once

class Player;
class SceneManager;

class MainApp
{
public:
	bool Intialize(HWND hWnd, HDC HDC, PAINTSTRUCT ps);
	void Update();
	void Render();
	void Release();

private:
	PAINTSTRUCT mPS;
	HWND mhWnd;
	HDC mHDC;
	Player* mPlayer;
	HDC mhMemdc;
	HBITMAP mhOldbitMap;
	RECT mRect;
	SceneManager* mSceneManager;
};

