#include "Scene.h"

bool to23 = true;

bool map2to3(float timeDelta)
{
		int Map[72][31] = { 0 };

	FileRead("Map2-3.txt");
	int PosX = 0, PosY = 0;

	//1번 틀

	for (int y = 0; y < 31; y++)
	{
		for (int x = 0; x < 72; x++)
		{
			ReadInt(&Map[x][y]);
			//0 = 없음
			if (Map[x][y] == 0) Draw((x * 2) + PosX, y + PosY, BLUE | BG_BLUE, "  ");
			//1 or 2 = 벽 생성
			else if (Map[x][y] == 1) Draw((x * 2) + PosX, y + PosY, WHITE | BG_WHITE, "■");
			else if (Map[x][y] == 2) Draw((x * 2) + PosX, y + PosY, GREEN | BG_GREEN, "■");
			//3-포탈
			else if (Map[x][y] == 3) Draw((x * 2) + PosX, y + PosY, PURPLE | BG_PURPLE, "■");
		}

	}

	FileClose();
	mapnumber2(6, "인더씨 3");
	userinfo_Render();
	skill();

	regen2 += timeDelta;
	//몬스터 리젠
	if (monDeath == false)
	{
	fish(timeDelta);
		regen2 = 0.0f;
	}
	else if (regen2 >= 5.0)
	{
		regen2 = 0.0f;
		monDeath = false;
		fishHP = 5000;
	}


	Char_Render(timeDelta);


	if (KeyDown(KEY_UP))
	{
		if (CharX <= 0)
		{
			SceneNumber = MAP_TWO_TWO;
			CharX = 130;
			CharY = 19;
			monDeath = false;
			to22 = true;
			to23 = false;
			lvup = false;
		}
		else if (128 <= CharX)
		{
			SceneNumber = MAP_TWO_BOSS;
			CharX = 6;
			CharY = 19;
			monDeath = false;
			to23 = false;
			to2boss = true;
		}
	}

	LOG(timeDelta);

	return true;
}
