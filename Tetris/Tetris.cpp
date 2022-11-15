#include"Tetris.h"

void Tetris::Run()
{
	int x;
	int y;

	while (true) // for random num gen purposes
	{
		x = analogRead(A0);
		y = analogRead(A1);

		if (x > 712)
			break;
		else if (x < 312)
			break;
		if (y > 712)
			break;
		else if (y < 312)
			break;
	}
	randomSeed(millis()); // <- see

	entity = Entity(static_cast<int>(random(0, 6)));

	while (true)
	{
		x = analogRead(A0);
		y = analogRead(A1);

		// use inputs
		if (x > 712)
		{
			entity.MoveRight(renderWindow.GetScreen());
		}
		else if (x < 312)
		{
			entity.MoveLeft(renderWindow.GetScreen());
		}
		if (y > 712)
		{
			entity.RotateCCW(renderWindow.GetScreen());
		}
		else if (y < 312)
		{
			entity.RotateCW(renderWindow.GetScreen());
		}

		renderWindow.Draw(entity); // draw call

		if (entity.Fall(renderWindow.GetScreen()))
		{
			delay(300); // classic tetris delay
			continue;
		}
		else
		{
			renderWindow.SetScreen(entity); // turn the entity into a part of the screen draw
			entity = Entity(static_cast<int>(random(0,6))); // random piece gen, again
			delay(400);
		}
	}
}