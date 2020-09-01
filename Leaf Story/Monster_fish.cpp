#include "Scene.h"

bool fish(float timeDelta)
{
	static float monMoveTimer = 0.0f;
	static bool monDirection = true;
	static int monMoveCount = 0;

	Draw(fishX, fishY, RED | BG_BLUE, "물고기 %d/5000", fishHP);
	Draw(fishX+4, fishY + 1, YELLOW | BG_YELLOW, "■■■■");
	Draw(fishX+2, fishY + 2, YELLOW | BG_YELLOW, "■■■■■■");
	Draw(fishX, fishY + 3, YELLOW | BG_YELLOW, "■■■■■■■■");
	Draw(fishX+2, fishY + 4, YELLOW | BG_YELLOW, "■■■■■■");
	Draw(fishX + 6, fishY + 5, YELLOW | BG_YELLOW, "■■■");
	Draw(fishX +16, fishY + 2, YELLOW | BG_YELLOW, "■■");
	Draw(fishX+16, fishY + 4, YELLOW | BG_YELLOW, "■■");
	Draw(fishX + 4, fishY + 2, BG_BLUE, "■");


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
		if (monDirection == false) fishX -= 1;
		else if (monDirection == true) fishX += 1;
		monMoveTimer = 0.0f;
	}

	//몬스터 사망 관련
	if (fishHP <= 0)
	{
		fishHP = 900;
		monDeath = true;

		goldbox = rand() % 20000 + 8000;
		if (goldbox > 20000) goldbox -= 8000;
		gold += goldbox;

		OUTEXP = rand() % 5000 + 1000;
		if (OUTEXP > 5000) OUTEXP -= 1000;
		charEXP += OUTEXP;
		OUTEXPTF = true;
	}

	//몬스터한테 닿으면 넉백
	if (chardie == false)
	{
		if (CharX + 10 == fishX)
		{
			charHP -= rand() % 700 + 350;
			CharX -= 4;
		}
		else if (CharX == fishX + 18)
		{
			charHP -= rand() % 700 + 350;
			if (CharX < 130)
				CharX += 4;
		}
	}
	return true;
}