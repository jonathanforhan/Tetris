#include"RenderWindow.h"

RenderWindow::RenderWindow()
{
	lc.shutdown(0, false);
	lc.setIntensity(0, 2);
	lc.clearDisplay(0);
}

void RenderWindow::Draw(Entity obj)
{
	for (int i{}; i < 8; i++)
	{
		for (int j{}; j < 8; j++)
		{
			bool val = screen[i * 8 + j];
			lc.setLed(0, j, i, val);
		}
	}

	for (int i{}; i < 9; i ++)
	{
		if(obj.GetVal(i) != 0)
			lc.setLed(0, obj.GetY(i), obj.GetX(i), 1);
	}
}

bool* RenderWindow::GetScreen()
{
	return screen;
}

const int RenderWindow::GetX()
{
	return x;
}

const int RenderWindow::GetY()
{
	return y;
}

void RenderWindow::SetScreen(Entity entity)
{
	for (int i{}; i < 9; i++)
	{
		if (entity.GetVal(i) != 0)
			screen[entity.GetX(i) * 8 + entity.GetY(i)] = 1;
	}

	CheckTetris();
	CheckLoss();
}

void RenderWindow::CheckTetris()
{
	for (int i{}; i < 8; i++)
	{
		int n = 0;
		for (int j = 0; j < 8; j++)
		{
			if (screen[j * 8 + i] == 1)
			{
				n++;
			}
			if (n == 8)
			{
				for (int k = 0; k < 8; k++)
				{
					screen[k * 8 + i] = 0;
				}
				
				for (int k = i; k > 0; k--)
				{
					for (int l = 0; l < 8; l++)
					{
						Swap(screen[l * 8 + k], screen[l * 8 + k - 1]);
					}
				}
			}
		}
	}
}

void RenderWindow::CheckLoss()
{
	for (int i{}; i < 64; i+=8)
	{
		if (screen[i] == 1)
		{
			for (int j = 0; j < 64; j++)
			{
				screen[j] = 0;
			}
		}
	}
}

void RenderWindow::Swap(bool& a, bool& b)
{
	bool c = a;
	a = b;
	b = c;
}