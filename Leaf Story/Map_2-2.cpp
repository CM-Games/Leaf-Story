#include "Scene.h"

bool to22 = true;

bool map2to2(float timeDelta)
{


	int Map[72][31] = { 0 };

	FileRead("Map2-2.txt");
	int PosX = 0, PosY = 0;

	//1�� Ʋ

	for (int y = 0; y < 31; y++)
	{
		for (int x = 0; x < 72; x++)
		{
			ReadInt(&Map[x][y]);
			//0 = ����
			if (Map[x][y] == 0) Draw((x * 2) + PosX, y + PosY, BLUE | BG_BLUE, "  ");
			//1 or 2 = �� ����
			else if (Map[x][y] == 1) Draw((x * 2) + PosX, y + PosY, WHITE | BG_WHITE, "��");
			else if (Map[x][y] == 2) Draw((x * 2) + PosX, y + PosY, GREEN | BG_GREEN, "��");
			//3-��Ż
			else if (Map[x][y] == 3) Draw((x * 2) + PosX, y + PosY, PURPLE | BG_PURPLE, "��");
		}

	}

	FileClose();
	mapnumber2(6, "�δ��� 2");
	userinfo_Render();
	skill();

	regen2 += timeDelta;
	//���� ����
	if (monDeath == false)
	{
		ston(timeDelta);
		regen2 = 0.0f;
	}
	else if (regen2 >= 5.0)
	{
		regen2 = 0.0f;
		monDeath = false;
		stonHP = 3500;
	}


	Char_Render(timeDelta);


	if (KeyDown(KEY_UP))
	{
		if (CharX <= 0)
		{
			SceneNumber = MAP_TWO_ONE;
			CharX = 130;
			CharY = 19;
			monDeath = false;
			to21 = true;
			to22 = false;
			lvup = false;
		}
		else if (128 <= CharX)
		{
			SceneNumber = MAP_TWO_THREE;
			CharX = 6;
			CharY = 19;
			monDeath = false;
			to22 = false;
			to23 = true;
		}
	}

	LOG(timeDelta);

	return true;
}
