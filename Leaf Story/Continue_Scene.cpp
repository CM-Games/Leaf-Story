#include "Scene.h"
int readc[256];

bool Continue_Scene_Render(float timeDelta)
{
	SceneNumber = MAP_ONE;
	userinfo();
	return true;
}

void userinfo()

{
	FileRead("info.txt");

	ReadText(readname);

	for (int i = 0; i < 256; i++)
	{
		if (readname[i] == '\r')
		{
			readname[i] = NULL;
			readname[i + 1] = NULL;
		}
	}
	for (int i = 0; i < 256; i++)
	{
		ReadInt(&readc[i]);
	}

	for (int i = 0; i < 256; i++)
	{
		if (readc[i] == 0)
			break;
		else
		{
			sex = readc[0];
			charLV = readc[1];
			charEXP = readc[2];
			expbar = readc[3];
			mini_attack = readc[4];
			max_attack = readc[5];
			charHP = readc[6];
			max_charHP = readc[7];
			charMP = readc[8];
			potion = readc[9];
			gold = readc[10];
			upgradeN = readc[11];
		}
	}
	FileClose();
}