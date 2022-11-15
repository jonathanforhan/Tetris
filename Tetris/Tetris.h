#pragma once

/* Jonathan Forhan, This is the wrapper class, nothing special
 *
 * Press analog to start, then i use millis() to get completely random generation, kinda a lifehack
 *
 * I have no menus or anything and the rotatation is blocked on the side to prevent
 * unexpected behavoir, if I have enough interest may fix it
 * 
 */

#include<Arduino.h>
#include<LedControl.h>

#include"RenderWindow.h"
#include"Entity.h"

class Tetris
{
public:
	void Run();
private:
	RenderWindow renderWindow;
	Entity entity = Entity(0);
};