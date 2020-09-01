#include "Scene.h"

bool facebook(float timeDelta)
{
	static float monMoveTimer = 0.0f;
	static bool monDirection = true;
	static int monMoveCount = 0;

	Draw(FBX, FBY, RED|BG_BLUE, "페이스북 %d/3000", facebookHP);
	Draw(FBX, FBY + 1, BLUE | BG_BLUE, "■■■■■■■■■");
	Draw(FBX, FBY + 2, BLUE | BG_BLUE, "■              ■");
	Draw(FBX, FBY + 3, BLUE | BG_BLUE, "■              ■");
	Draw(FBX, FBY + 4, BLUE | BG_BLUE, "■              ■");
	Draw(FBX, FBY + 5, BLUE | BG_BLUE, "■              ■");
	Draw(FBX, FBY + 6, BLUE | BG_BLUE, "■              ■");
	Draw(FBX, FBY + 7, BLUE | BG_BLUE, "■              ■");
	Draw(FBX, FBY + 8, BLUE | BG_BLUE, "■              ■");
	Draw(FBX, FBY + 9, BLUE | BG_BLUE, "■■■■■■■■■");

	Draw(FBX+8, FBY + 3, WHITE|BG_WHITE, "####");
	Draw(FBX+8, FBY + 4, WHITE | BG_WHITE, "##");
	Draw(FBX+6, FBY + 5, WHITE | BG_WHITE, "######");
	Draw(FBX+8, FBY + 6, WHITE | BG_WHITE, "##");
	Draw(FBX+8, FBY + 7, WHITE | BG_WHITE, "##");
	Draw(FBX+8, FBY + 8, WHITE | BG_WHITE, "##");


	monMoveTimer += timeDelta;

	//몬스터 이동
	if (monMoveTimer >= 0.1f)
	{
		monMoveCount += 1;
		if (monMoveCount == 40)
		{
			if (monDirection == false) monDirection = true;
			else if (monDirection == true) monDirection = false;
			monMoveCount = 0;
		}
		if (monDirection == false) FBX -= 1;
		else if (monDirection == true) FBX += 1;
		monMoveTimer = 0.0f;
	}

	//몬스터 사망 관련
	if (facebookHP <= 0)
	{
		facebookHP = 900;
		monDeath = true;

		goldbox = rand() % 15000 + 8000;
		if (goldbox > 15000) goldbox -= 8000;
		gold += goldbox;

		OUTEXP = rand() % 3500 + 1000;
		if (OUTEXP > 3500) OUTEXP -= 1000;
		charEXP += OUTEXP;
		OUTEXPTF = true;
	}

	//몬스터한테 닿으면 넉백
	if (chardie == false)
	{
		if (CharX + 10 == FBX)
		{
			charHP -= rand() % 500 + 350;
			CharX -= 4;
		}
		else if (CharX == FBX + 18)
		{
			charHP -= rand() % 500 + 350;
			if (CharX < 130)
				CharX += 4;
		}
	}
	return true;
}