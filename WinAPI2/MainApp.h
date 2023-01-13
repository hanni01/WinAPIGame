#pragma once

class Player;
class SceneManager;

class MainApp
{
public:
	bool Intialize(HDC HDC);
	void Update();
	void Render();
	void Release();

private:
	HDC mHDC;
	Player* mPlayer;
	SceneManager* mSceneManager;
};

