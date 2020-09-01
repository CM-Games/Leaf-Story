#include "Scene.h"

bool ston(float timeDelta)
{
	static float monMoveTimer = 0.0f;
	static bool monDirection = true;
	static int monMoveCount = 0;

	Draw(stonX, stonY, RED | BG_BLUE, "돌맹이 %d/3500", stonHP);
	Draw(stonX+8, stonY + 1, GARY | BG_GARY, "■■■■");
	Draw(stonX+6, stonY + 2, GARY | BG_GARY, "■■■■■");
	Draw(stonX+4, stonY + 3, GARY | BG_GARY, "■■■■■■■");
	Draw(stonX+2, stonY + 4, GARY | BG_GARY, "■■■■■■■■");
	Draw(stonX, stonY + 5, GARY | BG_GARY, "■              ■");
	Draw(stonX, stonY + 6, GARY | BG_GARY, "■              ■");
	Draw(stonX, stonY + 7, GARY | BG_GARY, "■■■■■■■■■");

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
		if (monDirection == false) stonX -= 1;
		else if (monDirection == true) stonX += 1;
		monMoveTimer = 0.0f;
	}

	//몬스터 사망 관련
	if (stonHP <= 0)
	{
		stonHP = 900;
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
		if (CharX + 10 == stonX)
		{
			charHP -= rand() % 700 + 350;
			CharX -= 4;
		}
		else if (CharX == stonX + 18)
		{
			charHP -= rand() % 700 + 350;
			if (CharX < 130)
				CharX += 4;
		}
	}
	return true;
}