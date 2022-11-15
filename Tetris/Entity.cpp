#include"Entity.h"

Entity::Entity(int type)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			point[i * 3 + j].x = j+3;
			point[i * 3 + j].y = i-1;
		}
	}

	// types of pieces
	switch (type)
	{
	case 0: // line
	{
		int arr[9] = {
			0, 1, 0,
			0, 1, 0,
			0, 1, 0
		};
		for (int i{}; i < 9; i++)
		{
			point[i].val = arr[i];
		}
		break;
	}
	case 1: // pipe
	{
		int arr[9] = {
			0, 1, 0,
			1, 1, 1,
			0, 0, 0
		};
		for (int i{}; i < 9; i++)
		{
			point[i].val = arr[i];
		}
		break;
	}
	case 2: // right L
	{
		int arr[9] = {
			0, 1, 0,
			0, 1, 0,
			0, 1, 1
		};
		for (int i{}; i < 9; i++)
		{
			point[i].val = arr[i];
		}
		break;
	}
	case 3: // left L
	{
		int arr[9] = {
			0, 1, 0,
			0, 1, 0,
			1, 1, 0
		};
		for (int i{}; i < 9; i++)
		{
			point[i].val = arr[i];
		}
		break;
	}
	case 4: // square
	{
		int arr[9] = {
			0, 0, 0,
			1, 1, 0,
			1, 1, 0
		};
		for (int i{}; i < 9; i++)
		{
			point[i].val = arr[i];
		}
		break;
	}
	case 5: // elbow
	{
		int arr[9] = {
			0, 0, 0,
			1, 1, 0,
			0, 1, 0
		};
		for (int i{}; i < 9; i++)
		{
			point[i].val = arr[i];
		}
		break;
	}

	default:
		break;
	}
}

void Entity::RotateCW(bool* screen)
{
	for (int i = 0; i < 9; i++)
	{
		if (point[i].val == 0)
		{
			continue;
		}
		else if ((screen[(point[i].x) * 8 + point[i].y + 8] == 1 || point[i].x == 7) && screen[5] == 0)
		{
			return;
		}
		else if ((screen[(point[i].x) * 8 + point[i].y - 8] == 1 || point[i].x == 0) && screen[3] == 0)
		{
			return;
		}
		else if (point[i].y == 7)
		{
			return;
		}
		else if (screen[(point[i].x) * 8 + point[i].y + 1] == 1)
		{
			return;
		}
	}

	Swap(point[8].val, point[6].val);
	Swap(point[2].val, point[8].val);
	Swap(point[0].val, point[2].val);

	Swap(point[3].val, point[7].val);
	Swap(point[7].val, point[5].val);
	Swap(point[5].val, point[1].val);
}

void Entity::RotateCCW(bool* screen)
{
	for (int i = 0; i < 9; i++)
	{
		if (point[i].val == 0)
		{
			continue;
		}
		else if ((screen[(point[i].x) * 8 + point[i].y + 8] == 1 || point[i].x == 7) && screen[5] == 0)
		{
			return;
		}
		else if ((screen[(point[i].x) * 8 + point[i].y - 8] == 1 || point[i].x == 0) && screen[3] == 0)
		{
			return;
		}
		else if (point[i].y == 7)
		{
			return;
		}
		else if (screen[(point[i].x) * 8 + point[i].y + 1] == 1)
		{
			return;
		}
	}

	Swap(point[0].val, point[2].val);
	Swap(point[2].val, point[8].val);
	Swap(point[8].val, point[6].val);

	Swap(point[5].val, point[1].val);
	Swap(point[7].val, point[5].val);
	Swap(point[3].val, point[7].val);
}			  

void Entity::MoveRight(bool* screen)
{
	for (int i = 0; i < 9; i++)
	{
		if (point[i].val == 0)
		{
			continue;
		}
		else if (screen[(point[i].x) * 8 + point[i].y + 8] == 1 || point[i].x == 7)
		{
			return;
		}
	}
	for (int i{}; i < 9; i++)
	{
		point[i].x += 1;
	}
}

void Entity::MoveLeft(bool* screen)
{
	for (int i = 0; i < 9; i++)
	{
		if (point[i].val == 0)
		{
			continue;
		}
		else if (screen[(point[i].x) * 8 + point[i].y - 8] == 1 || point[i].x == 0)
		{
			return;
		}
	}
	for (int i{}; i < 9; i++)
	{
		point[i].x -= 1;
	}
}

bool Entity::Fall(bool* screen)
{
	if (FallCeck(screen))
	{
		for (int i{}; i < 9; i++)
		{
			point[i].y += 1;
		}
		return true;
	}
	else
	{
		return false;
	}
}

int Entity::GetX(int i)
{
	return point[i].x;
}

int Entity::GetY(int i)
{
	return point[i].y;
}

bool Entity::GetVal(int i)
{
	return point[i].val;
}

bool Entity::FallCeck(bool* screen)
{
	for (int i = 0; i < 9; i++)
	{
		if (point[i].val == 0)
		{
			continue;
		}
		else if (point[i].y == 7)
		{
			return false;
		}
		else if (screen[(point[i].x) * 8 + point[i].y + 1] == 1)
		{
			return false;
		}
	}
	return true;
}

void Entity::Swap(bool& a, bool& b)
{
	bool c = a;
	a = b;
	b = c;
}