#include "Scene.h"

float goldtimer = 0.0f; // 골드 부족 알림
bool goldless = false; // 골드 부족
bool selet = false;
char pocolor = RED;
char lvcolor=GARY;

bool shop_render(float timeDelta)
{
	int shopX = 22, shopY = 5;
	goldtimer += timeDelta;
	
	//상점 틀
	Draw(60, 3, GREEN, "[    리    프    상    점    ]");
	Draw(shopX, shopY, YELLOW | BG_YELLOW, "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	Draw(shopX, shopY + 1, YELLOW | BG_YELLOW, "■");
	Draw(shopX + 98, shopY + 1, YELLOW | BG_YELLOW, "■");
	Draw(shopX, shopY + 2, YELLOW | BG_YELLOW, "■");
	Draw(shopX + 98, shopY + 2, YELLOW | BG_YELLOW, "■");
	Draw(shopX, shopY + 3, YELLOW | BG_YELLOW, "■");
	Draw(shopX + 98, shopY + 3, YELLOW | BG_YELLOW, "■");
	Draw(shopX, shopY + 4, YELLOW | BG_YELLOW, "■");
	Draw(shopX + 98, shopY + 4, YELLOW | BG_YELLOW, "■");
	Draw(shopX, shopY + 5, YELLOW | BG_YELLOW, "■");
	Draw(shopX + 98, shopY + 5, YELLOW | BG_YELLOW, "■");
	Draw(shopX, shopY + 6, YELLOW | BG_YELLOW, "■");
	Draw(shopX + 98, shopY + 6, YELLOW | BG_YELLOW, "■");
	Draw(shopX, shopY + 7, YELLOW | BG_YELLOW, "■");
	Draw(shopX + 98, shopY + 7, YELLOW | BG_YELLOW, "■");
	Draw(shopX, shopY + 8, YELLOW | BG_YELLOW, "■");
	Draw(shopX + 98, shopY + 8, YELLOW | BG_YELLOW, "■");
	Draw(shopX, shopY + 9, YELLOW | BG_YELLOW, "■");
	Draw(shopX + 98, shopY + 9, YELLOW | BG_YELLOW, "■");
	Draw(shopX, shopY + 10, YELLOW | BG_YELLOW, "■");
	Draw(shopX + 98, shopY + 10, YELLOW | BG_YELLOW, "■");
	Draw(shopX, shopY + 11, YELLOW | BG_YELLOW, "■");
	Draw(shopX + 98, shopY + 11, YELLOW | BG_YELLOW, "■");
	Draw(shopX, shopY + 12, YELLOW | BG_YELLOW, "■");
	Draw(shopX + 98, shopY + 12, YELLOW | BG_YELLOW, "■");
	Draw(shopX, shopY + 13, YELLOW | BG_YELLOW, "■");
	Draw(shopX + 98, shopY + 13, YELLOW | BG_YELLOW, "■");
	Draw(shopX, shopY + 14, YELLOW | BG_YELLOW, "■");
	Draw(shopX + 98, shopY + 14, YELLOW | BG_YELLOW, "■");
	Draw(shopX, shopY + 15, YELLOW | BG_YELLOW, "■");
	Draw(shopX + 98, shopY + 15, YELLOW | BG_YELLOW, "■");
	Draw(shopX, shopY + 16, YELLOW | BG_YELLOW, "■");
	Draw(shopX + 98, shopY + 16, YELLOW | BG_YELLOW, "■");
	Draw(shopX, shopY + 17, YELLOW | BG_YELLOW, "■");
	Draw(shopX + 98, shopY + 17, YELLOW | BG_YELLOW, "■");
	Draw(shopX, shopY + 18, YELLOW | BG_YELLOW, "■");
	Draw(shopX + 98, shopY + 18, YELLOW | BG_YELLOW, "■");
	Draw(shopX, shopY + 19, YELLOW | BG_YELLOW, "■");
	Draw(shopX + 98, shopY + 19, YELLOW | BG_YELLOW, "■");
	Draw(shopX, shopY + 20, YELLOW | BG_YELLOW, "■");
	Draw(shopX + 98, shopY + 20, YELLOW | BG_YELLOW, "■");
	Draw(shopX, shopY + 21, YELLOW | BG_YELLOW, "■");
	Draw(shopX + 98, shopY + 21, YELLOW | BG_YELLOW, "■");
	Draw(shopX, shopY + 22, YELLOW | BG_YELLOW, "■");
	Draw(shopX + 98, shopY + 22, YELLOW | BG_YELLOW, "■");
	Draw(shopX, shopY + 23, YELLOW | BG_YELLOW, "■");
	Draw(shopX + 98, shopY + 23, YELLOW | BG_YELLOW, "■");
	Draw(shopX, shopY + 24, YELLOW | BG_YELLOW, "■");
	Draw(shopX + 98, shopY + 24, YELLOW | BG_YELLOW, "■");
	Draw(shopX, shopY + 25, YELLOW | BG_YELLOW, "■");
	Draw(shopX + 98, shopY + 25, YELLOW | BG_YELLOW, "■");
	Draw(shopX, shopY + 26, YELLOW | BG_YELLOW, "■");
	Draw(shopX + 98, shopY + 26, YELLOW | BG_YELLOW, "■");
	Draw(shopX, shopY + 27, YELLOW | BG_YELLOW, "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");



	//물약 상품

	static int poN = 1;

	Draw(shopX + 19, shopY + 5, WHITE, "[ 포 션 ]");
	Draw(shopX + 10, shopY + 6, pocolor, "▼▼▼▼▼▼▼▼▼▼▼▼▼▼");

	Draw(shopX + 23, shopY + 9, RED | BG_RED, "■");
	Draw(shopX + 21, shopY + 10, RED | BG_RED, "■■■");
	Draw(shopX + 21, shopY + 11, RED | BG_RED, "■■■");
	Draw(shopX + 21, shopY + 12, RED | BG_RED, "■■■");

	Draw(shopX + 14, shopY + 14, RED, "최대 체력의 50%% 회복");
	Draw(shopX + 17, shopY + 16, WHITE, "소지갯수 : %d 개", potion);
	Draw(shopX + 13, shopY + 17, WHITE, "상품 가격(1개) : 500 G");

	Draw(shopX + 12, shopY + 19, WHITE, "[+] = 키↑ , [-] = 키↓");
	Draw(shopX + 16, shopY + 20, GREEN, "구매 개수 : %d 개", poN);
	Draw(shopX + 17, shopY + 22, WHITE, " 구매 = ENTER ");
	Draw(shopX + 15, shopY + 23, GREEN, "지불 금액 : %d G", poN * 500);


	//경험치 보조상품
	static int lvN = 1;

	Draw(shopX + 69, shopY + 5, WHITE, "[ LV1 UP ]");
	Draw(shopX + 60, shopY + 6, lvcolor, "▼▼▼▼▼▼▼▼▼▼▼▼▼▼");

	Draw(shopX + 66, shopY + 7, SKYBLUE, "■  ■   ■■■");
	Draw(shopX + 66, shopY + 8, SKYBLUE, "■  ■   ■  ■");
	Draw(shopX + 66, shopY + 9, SKYBLUE, "■  ■   ■■■");
	Draw(shopX + 66, shopY + 10, SKYBLUE, "■■■   ■");

	Draw(shopX + 62, shopY + 12, RED, "필요경험치만큼 경험치획득");
	Draw(shopX + 62, shopY + 13, RED, "레벨: %d , 경험치 %d/%d",charLV,charEXP,expbar);
	Draw(shopX + 66, shopY + 16, WHITE, "구매시 바로 적용");
	Draw(shopX + 62, shopY + 17, WHITE, "상품 가격(1개) : 30000G");

	Draw(shopX + 62, shopY + 19, WHITE, "[+] = 키↑ , [-] = 키↓");
	Draw(shopX + 66, shopY + 20, GREEN, "구매 개수 : %d 개", lvN);
	Draw(shopX + 67, shopY + 22, WHITE, " 구매 = ENTER ");
	Draw(shopX + 65, shopY + 23, GREEN, "지불 금액 : %d G", lvN * 30000);

	//상품 구매 제어
	if (KeyDown(KEY_RIGHT))
	{
		pocolor = GARY;
		lvcolor = RED;
		selet = true;
	}
	else if (KeyDown(KEY_LEFT))
	{
		pocolor = RED;
		lvcolor = GARY;
		selet = false;
	}
	else if (KeyDown(KEY_UP))
	{
		if (selet == false) poN += 1;
		else lvN += 1;
	}

	else if (KeyDown(KEY_DOWN))
	{
		if (selet == false)
		{
			if (poN != 0) poN -= 1;
		}
		else
		{
			if (lvN != 0) lvN -= 1;
		}
	}
	else if (KeyDown(KEY_ESC))
		SceneNumber = MENU_SCENE;
	else if (KeyDown(KEY_ENTER))
	{
		goldtimer = 0.0f;
		if (selet == false)
		{
			if (gold < poN * 500)
				goldless = true;
			else
			{
				gold -= poN * 500;
				potion += poN;
			}
		}
		else
		{
			if (gold < lvN * 30000)
				goldless = true;
			else
			{
				gold -= lvN * 30000;
				for (int i = 0; i < lvN + 1; )
				{
					charEXP += expbar;
					i++;
				}

			}
		}
	}

	//골드 부족시
	if (goldless == true)
	{
		if (goldtimer <= 3.0)
			Draw(shopX + 33, shopY + 2, YELLOW, "[알림!] 구매 하기 위한 골드가 부족합니다!");
		else goldless = false;
	}

	Draw(shopX + 45, shopY + 30, YELLOW, "소지 골드 : %d", gold);
	Draw(shopX + 45, shopY + 32, SKYBLUE, " 나가기 - ESC");

	//레벨업
	if (charEXP >= expbar)
	{
		expbox += (charEXP - expbar);
		charEXP = expbox;
		expbox = 0;
		charLV++;
		expbar += 50;
		charHP += 50;
		max_charHP += 50;
		max_attack += 30;
		mini_attack += 10;
	}

	
	return true;
}