#include "Scene.h"

bool to2boss = true;

bool map2boss(float timeDelta)
{
	int Map[72][31] = { 0 };

	FileRead("Map2-boss.txt");
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
	mapnumber2(6, "최종 보스");
	userinfo_Render();
	skill();


	if (lastbossdie1 == false)
		door(timeDelta);
	else
	{
		Draw(60, 13, RED | BG_BLUE, "최종 보스 클리어~!");
		Draw(60, 14, RED | BG_BLUE, "지금까지 이용해주셔서 감사합니다");

				Draw(60, 15, RED | BG_BLUE, "무료 체험판이 종료되었습니다.");
				Draw(60, 16, RED | BG_BLUE, "더 하실려면 결제 해주세요.");
		
	}



	Char_Render(timeDelta);


	LOG(timeDelta);

	return true;
}
