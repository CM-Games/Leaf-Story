#include "Scene.h"

bool to3;

bool map1to3(float timeDelta)
{
	if (map1 == true)
	{
		titlemusic(3, 0.5);
		map1 = false;
	}
	int Map[72][31] = { 0 };

	FileRead("Map1-3.txt");
	int PosX = 0, PosY = 0;


	for (int y = 0; y < 31; y++)
	{
		for (int x = 0; x < 72; x++)
		{
			ReadInt(&Map[x][y]);
			//0 = 없음
			if (Map[x][y] == 0) Draw((x * 2) + PosX, y + PosY, SKYBLUE | BG_SKYBLUE, "  ");
			//1 or 2 = 벽 생성
			else if (Map[x][y] == 1) Draw((x * 2) + PosX, y + PosY, WHITE | BG_WHITE, "■");
			else if (Map[x][y] == 2) Draw((x * 2) + PosX, y + PosY, GREEN | BG_GREEN, "■");
			//3-포탈
			else if (Map[x][y] == 3) Draw((x * 2) + PosX, y + PosY, PURPLE | BG_PURPLE, "■");
		}

	}
	FileClose();

	mapnumber(5, "평화로운길 3");
	userinfo_Render();
	skill();

	regen += timeDelta;
	//몬스터 리젠
	if (monDeath == false)
	{
		slime(timeDelta);
		regen = 0.0f;
	}
	else if (regen >= 5.0)
	{
		regen = 0.0f;
		monDeath = false;
		slimeHP = 900;
	}

	//캐릭터
	Char_Render(timeDelta);

	if (KeyDown(KEY_UP))
	{
		if (CharX <= 0)
		{
			SceneNumber = MAP_TWO;
			CharX = 130;
			CharY = 19;
			monDeath = false;
			to3 = false;
			lvup = false;
		}
		else if (128 <= CharX)
		{
			if (bossdie == false)
			{
				SceneNumber = MAP_BOSS;
				CharX = 6;
				CharY = 19;
				monDeath = false;
				to3 = false;
				toboss = true;
			}
			else
			{
				SceneNumber = MAP_TWO_ONE;
				CharX = 6;
				CharY = 19;
				monDeath = false;
				to3 = false;
				to21 = true;
			}

		}
	}

	LOG(timeDelta);

	return true;
}
