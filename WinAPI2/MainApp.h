#pragma once

class Player;
class SceneManager;

class MainApp
{
public:
	bool Intialize(HDC HDC, PAINTSTRUCT ps);
	void Update();
	void Render();
	void Release();

private:
	PAINTSTRUCT mPS;
	HDC mHDC;
	Player* mPlayer;
	SceneManager* mSceneManager;
};

