#pragma once

#include<Arduino.h>
#include"Util.h"

class Entity
{
public:
	Entity(int type);

	void RotateCW(bool* screen);
	void RotateCCW(bool* screen);

	void MoveRight(bool* screen);
	void MoveLeft(bool* screen);

	bool Fall(bool* screen);

	int GetX(int i);
	int GetY(int i);
	bool GetVal(int i);
private:
	bool FallCeck(bool* screen);

	void Swap(bool& a, bool& b);

	Point point [9];
};