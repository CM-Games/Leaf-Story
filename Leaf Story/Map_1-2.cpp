#include "Scene.h"

bool to2;

bool map1to2(float timeDelta)
{
	if (map1 == true)
	{
		titlemusic(3, 0.5);
		map1 = false;
	}
	int Map[72][31] = { 0 };

	FileRead("Map1-2.txt");
	int PosX = 0, PosY = 0;

	//1�� Ʋ
	for (int y = 0; y < 31; y++)
	{
		for (int x = 0; x < 72; x++)
		{
			ReadInt(&Map[x][y]);
			//0 = ����
			if (Map[x][y] == 0) Draw((x * 2) + PosX, y + PosY, SKYBLUE | BG_SKYBLUE, "  ");
			//1 or 2 = �� ����
			else if (Map[x][y] == 1) Draw((x * 2) + PosX, y + PosY, WHITE | BG_WHITE, "��");
			else if (Map[x][y] == 2) Draw((x * 2) + PosX, y + PosY, GREEN | BG_GREEN, "��");
			//3-��Ż
			else if (Map[x][y] == 3) Draw((x * 2) + PosX, y + PosY, PURPLE | BG_PURPLE, "��");
		}

	}
	FileClose();

	mapnumber(5, "��ȭ�ο� ��2");
		userinfo_Render();
		skill();


		regen += timeDelta;
	//���� ����
	if (monDeath == false)
	{
		munuh(timeDelta);
		regen = 0.0f;
	}
	else if (regen >= 5.0)
	{
		regen = 0.0f;
		monDeath = false;
		munuhHP = 500;
	}

	//ĳ����
Char_Render(timeDelta);

	if (KeyDown(KEY_UP))
	{
		if (CharX <= 0)
		{
			SceneNumber = MAP_ONE;
			CharX = 130;
			CharY = 19;
			monDeath = false;
			to1 = true;
			to2 = false;
			lvup = false;
		}
		else if (128 <= CharX)
		{
			SceneNumber = MAP_THREE;
			CharX = 6;
			CharY = 19;
			monDeath = false;
			to2 = false;
			to3 = true;
		}
	}

	LOG(timeDelta);

	return true;
}
