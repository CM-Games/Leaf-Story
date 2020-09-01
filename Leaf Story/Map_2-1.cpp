#include "Scene.h"

float regen2 = 0.0f;
bool to21 = true;

bool map2to1(float timeDelta)
{
	if (map2 == true)
	{
		titlemusic(11, 0.3);
		map2 = false;
	}

	int Map[72][31] = { 0 };

	FileRead("Map2-2.txt");
	int PosX = 0, PosY = 0;

	//1¹ø Æ²

	for (int y = 0; y < 31; y++)
	{
		for (int x = 0; x < 72; x++)
		{
			ReadInt(&Map[x][y]);
			//0 = ¾øÀ½
			if (Map[x][y] == 0) Draw((x * 2) + PosX, y + PosY, BLUE | BG_BLUE, "  ");
			//1 or 2 = º® »ý¼º
			else if (Map[x][y] == 1) Draw((x * 2) + PosX, y + PosY, WHITE | BG_WHITE, "¡á");
			else if (Map[x][y] == 2) Draw((x * 2) + PosX, y + PosY, GREEN | BG_GREEN, "¡á");
			//3-Æ÷Å»
			else if (Map[x][y] == 3) Draw((x * 2) + PosX, y + PosY, PURPLE | BG_PURPLE, "¡á");
		}

	}

	FileClose();
	mapnumber2(6, "ÀÎ´õ¾¾ 1");
	userinfo_Render();
	skill();

	regen2 += timeDelta;
	//¸ó½ºÅÍ ¸®Á¨
	if (monDeath == false)
	{
	facebook(timeDelta);
		regen2 = 0.0f;
	}
	else if (regen2 >= 5.0)
	{
		regen2 = 0.0f;
		monDeath = false;
		facebookHP = 3000;
	}

	Char_Render(timeDelta);


	if (KeyDown(KEY_UP))
	{
		if (CharX <= 0)
		{
			SceneNumber = MAP_THREE;
			CharX = 130;
			CharY = 19;
			monDeath = false;
			to21 = false;
			to3 = true;
			lvup = false;
		}

		if (128 <= CharX)
		{
			SceneNumber = MAP_TWO_TWO;
			CharX = 6;
			CharY = 19;
			monDeath = false;
			to21 = false;
			to22 = true;
			lvup = false;
		}
	}

	LOG(timeDelta);

	return true;
}

//¸Ê ¹øÈ£
void mapnumber2(int x, char name[256])
{
	Draw(1, 1, WHITE|BG_BLUE, "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤");
	Draw(1, 2, WHITE | BG_BLUE, "¦¢");
	Draw(1, 3, WHITE | BG_BLUE, "¦¢");
	Draw(1, 4, WHITE | BG_BLUE, "¦¢");
	Draw(19, 2, WHITE | BG_BLUE, "¦¢");
	Draw(19, 3, WHITE | BG_BLUE, "¦¢");
	Draw(19, 4, WHITE | BG_BLUE, "¦¢");
	Draw(1, 5, WHITE | BG_BLUE, "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥");
	Draw(x, 3, WHITE | BG_BLUE, "%s", name);
}