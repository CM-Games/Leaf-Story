#include "Scene.h"

float regen = 0.0f;
float outtimer = 0.0f;
bool to1 = true;
char Acolor;

bool map1to1(float timeDelta)
{
	if (map1 == true)
	{
	titlemusic(3,0.5);
	map1 = false;
	}
	
	int Map[72][31] = { 0 };

	FileRead("Map1-1.txt");
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
		}

	}

	FileClose();
	mapnumber(5,"평화로운 길1");
	userinfo_Render();
	skill();

	regen += timeDelta;
	//몬스터 리젠
	if (monDeath == false)
	{
		ice(timeDelta);
		regen = 0.0f;
	}
	else if (regen >= 5.0)
	{
		regen = 0.0f;
		monDeath = false;
		iceHP = 200;
			}

	Char_Render(timeDelta);


	if (KeyDown(KEY_UP))
	{
		if (128 <= CharX)
		{
			SceneNumber = MAP_TWO;
			CharX = 6;
			CharY = 19;
			monDeath = false;
			to1 = false;
			to2 = true;
			lvup = false;
		}
	}

	LOG(timeDelta);
	
	return true;
}

//유저 정보
void userinfo_Render()
{
	Draw(10, 33, WHITE, "닉네임 : %s", readname);
	if (sex == 1) Draw(10, 35, WHITE, "성별 : 남자");
	else if (sex == 2) Draw(10, 35, WHITE, "성별 : 여자");

	Draw(40, 33, WHITE, "레벨 : %d", charLV);
	Draw(35, 35, WHITE, "경험치 : %d / %d", charEXP, expbar);
	Draw(35, 37, WHITE, "공격력 : %d ~ %d", mini_attack, max_attack);

	Draw(60, 33, RED, "HP : %d/%d(포션:%d개)", charHP,max_charHP,potion);
	Draw(60, 35, SKYBLUE, "MP : %d",charMP);
	Draw(60, 37, YELLOW, "소지 골드 : %d", gold);
}

//맵 번호
void mapnumber(int x,char name[256])
{
	Draw(1, 1, BG_SKYBLUE, "┏━━━━━━━━━━━━━━┓");
	Draw(1, 2, BG_SKYBLUE, "┃");
	Draw(1, 3, BG_SKYBLUE, "┃");
	Draw(1, 4, BG_SKYBLUE, "┃");
	Draw(17, 2, BG_SKYBLUE, "┃");
	Draw(17, 3, BG_SKYBLUE, "┃");
	Draw(17, 4, BG_SKYBLUE, "┃");
	Draw(1, 5, BG_SKYBLUE, "┗━━━━━━━━━━━━━━┛");
	Draw(x, 3, BG_SKYBLUE, "%s",name);
}

//경혐치 로그 출력
void LOG(float timeDelta)
{
	if (OUTEXPTF == true)
	{
		outtimer += timeDelta;
		Draw(130, 34, GREEN, "%d 경험치 획득", OUTEXP);
		Draw(130, 35, YELLOW, "%d 골드 획득", goldbox);
		if (outtimer > 2.0)
		{
			OUTEXPTF = false;
			outtimer = 0;
			OUTEXP = 0;
		}
	}
}

void skill()
{

	//마을가기
	Draw(85, 32, GREEN, "ESC");
	Draw(82, 33, GREEN, "┏━━━━━┓");
	Draw(82, 34, GREEN, "┃  ↔ ┃");
	Draw(82, 35, GREEN, "┃     ┃");
	Draw(82, 36, GREEN, "┗━━━━━┛");
	Draw(82, 37, GREEN, "마을가기");

	//포션먹기
	Draw(94, 32, GREEN, "1");
	Draw(98, 33, GREEN, "┏━━━━━┓");
	Draw(93, 34, GREEN, "┃     ┃");
	Draw(93, 35, GREEN, "┃     ┃");
	Draw(98, 36, GREEN, "┗━━━━━┛");
	Draw(91, 37, GREEN, "포션먹기");
	Draw(97, 34, RED, "♥");

	//기본 공격
	Draw(104, 32, GREEN, "Z");
	Draw(114, 33, GREEN, "┏━━━━━┓");
	Draw(104, 34, GREEN, "┃  ★ ┃");
	Draw(104, 35, GREEN, "┃     ┃");
	Draw(114, 36, GREEN, "┗━━━━━┛");
	Draw(102, 37, GREEN, "공격");

	//베기 공격	
	if (charLV >= 25)
	{

			if (Ause == false)
				Acolor = GREEN;
			else if (Ause == true)
			{
				Acolor = GARY;
				Draw(114, 38, Acolor, "쿨타임: %d초", (int)askillT);
			}
	}
	else
	{
		Ause = true;
		Acolor = GARY;
		Draw(109, 38, Acolor, "LV25 해금");

	}

	Draw(113, 32, Acolor, "A");
	Draw(130, 33, Acolor, "┏━━━━━┓");
	Draw(115, 34, Acolor, "┃  † ┃");
	Draw(115, 35, Acolor, "┃     ┃");
	Draw(130, 36, Acolor, "┗━━━━━┛");
	Draw(111, 37, Acolor, "베기");

}