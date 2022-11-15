#pragma once

#include<LedControl.h>

#include"Entity.h"

class RenderWindow
{
public:
	RenderWindow();

	void Draw(Entity object);

	bool* GetScreen();
	const int GetX();
	const int GetY();

	void SetScreen(Entity entity);
private:
	void CheckTetris();
	void CheckLoss();
	void Swap(bool& a, bool& b);

	const int x{ 8 };
	const int y{ 8 };
	LedControl lc = LedControl(12, 10, 11, 1);
	bool screen[64] = {};
};