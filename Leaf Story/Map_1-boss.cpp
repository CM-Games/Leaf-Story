#include "Scene.h"

bool toboss;
float bossDtimer = 11.0f; //보스 클리어 출력

bool map1toboss(float timeDelta)
{
	toboss = true;
	int Map[72][31] = { 0 };

	FileRead("Map1-boss.txt");
	int PosX = 0, PosY = 0;


	for (int y = 0; y < 31; y++)
	{
		for (int x = 0; x < 72; x++)
		{
			ReadInt(&Map[x][y]);
			//0 = 없음
			if (Map[x][y] == 0) Draw((x * 2) + PosX, y + PosY, SKYBLUE | BG_SKYBLUE, "  ");
			//1 or 2 = 벽 생성
			else if (Map[x][y] == 1) Draw((x * 2) + PosX, y + PosY, RED | BG_RED, "■");
			else if (Map[x][y] == 2) Draw((x * 2) + PosX, y + PosY, RED | BG_RED, "■");
		}

	}
	FileClose();

	mapnumber(5, "첫번째 보스");

	userinfo_Render();
	Char_Render(timeDelta);
	skill();

	if (bossdie == false)
	{
		donut(timeDelta);
	}
	else
	{
		bossDtimer -= timeDelta;
		if (bossDtimer > 0.0)
		{
			Draw(60, 7, RED | BG_SKYBLUE, "보스 처치 성공!");
			Draw(50, 8, BLUE | BG_SKYBLUE, "%d 초후 새로운 던전으로 이동 합니다!", (int)bossDtimer);
			titlemusic(4, 1);
		}
		else 
		{
			to1 = false;
			to2 = false;
			to3 = false;
			toboss = false;
			to21 = true;
			SceneNumber = MAP_TWO_ONE;
			CharX = 6;
			CharY = 19;
		}
	}

	return true;
}
