#include "Scene.h"
bool musicQ = true;

bool menu(float timeDelta)
{
	if (musicQ == true)
	{
	titlemusic(9, 0.3);
	musicQ = false;
	}
	
	int Map[72][31] = { 0 };

	FileRead("menu.txt");
	int PosX = 0, PosY = 0;

	//1번 틀

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

			Draw(26, 14, BLUE | BG_SKYBLUE, "【 상점 】");
			Draw(70, 14, BLUE | BG_SKYBLUE, "【 강화 】");
			Draw(113, 14, BLUE | BG_SKYBLUE, "【 게임 종료 】");
		}

	}
	FileClose();
	mapnumber(5, "리프 빌리지");
	Char_Render(timeDelta);
	userinfo_Render();
	skill();

	//각 문마다 기능
	if (KeyDown(KEY_UP))
	{
		if (CharX <= 0) // 원래맵으로 가기
		{
			titlemusic(10,1);
			if (to1 == true)
			{
				SceneNumber = MAP_ONE;
				CharX = 6;
				map1 = true;
			}
			else if (to2 == true)
			{
				SceneNumber = MAP_TWO;
				CharX = 6;
					map1 = true;
			}
			else if (to3 == true)
			{
				SceneNumber = MAP_THREE;
				CharX = 6;
				map1 = true;
			}
			else if (to21 == true)
			{
				SceneNumber = MAP_TWO_ONE;
					CharX = 6;
				map2 = true;
			}
			else if (to22 == true)
			{
				SceneNumber = MAP_TWO_TWO;
					CharX = 6;
				map2 = true;
			}
			else if (to23 == true)
			{
				SceneNumber = MAP_TWO_THREE;
					CharX = 6;
				map2 = true;
			}
		}
		else if (18 < CharX && CharX < 30)
		{
			SceneNumber = SHOP;
		}
		else if (62 < CharX &&CharX< 74)
		{
			SceneNumber = UPGRADE;
			//강화
		}
		else if (106 < CharX && CharX < 118)
		{
			if (gamesave() == false)
				return false;
		}
	}
	return true;
}

bool gamesave()
{
	FileWrite("info.txt");
	WriteText(readname); //이름
	WriteInt(sex);  //성별
	WriteInt(charLV); //레벨
	WriteInt(charEXP); //경험치
	WriteInt(expbar); //필요경험치
	WriteInt(mini_attack); // 최소공격력
	WriteInt(max_attack); // 최대공격력
	WriteInt(charHP); // 채력	
	WriteInt(max_charHP);//최대체력
	WriteInt(charMP); // 마력
	WriteInt(potion); // 포션개수
	WriteInt(gold); // 골드
	WriteInt(upgradeN); // 현재 무기 강화수치
	FileClose();
return false;
}