#include "Scene.h"

float monMoveTimer = 0.0f;
bool monDirection = true;
int monMoveCount = 0;


bool munuh(float timeDelta)
{
	Draw(munuhX+2, munuhY - 1, BLUE|BG_SKYBLUE, "문어 %d/500",munuhHP);
	Draw(munuhX+3, munuhY, PURPLE, "#########");
	Draw(munuhX+2, munuhY + 1, PURPLE, "## ○  ○ ##");
	Draw(munuhX+2, munuhY + 2, PURPLE, "##   -    ##");
	Draw(munuhX+2, munuhY + 3, PURPLE, "###########");
	Draw(munuhX+1, munuhY + 4, PURPLE, "## ### ##  #");
	Draw(munuhX+1, munuhY + 5, PURPLE, "#  ##  ##  ##");
	Draw(munuhX, munuhY + 6, PURPLE, "#   #   ##    #");

	monMoveTimer += timeDelta;

	//몬스터 이동
	if (monMoveTimer >= 0.1f)
	{
		monMoveCount += 1;
		if (monMoveCount == 45)
		{
			if (monDirection == false) monDirection = true;
			else if (monDirection == true) monDirection = false;
			monMoveCount = 0;
		}
		if (monDirection == false) munuhX -= 1;
		else if (monDirection == true) munuhX += 1;
		monMoveTimer = 0.0f;
	}

	//몬스터 사망 관련
	if (munuhHP <= 0)
	{
		munuhHP = 500;
		monDeath = true;

		goldbox = rand() % 1500 + 500;
		if (goldbox > 1500) goldbox -= 500;
		gold += goldbox;

		OUTEXP = rand() % 200 + 50;
		if (OUTEXP > 200) OUTEXP -= 50;
		charEXP += OUTEXP;
		OUTEXPTF = true;
	}

	//몬스터한테 닿으면 넉백
	if (chardie == false)
	{
		if (CharX + 10 == munuhX)
		{
			charHP -= rand() % 100 + 50;
			CharX -= 4;
		}
		else if (CharX == munuhX + 8)
		{
			charHP -= rand() % 25 + 10;
			if (CharX < 130)
				CharX += 4;
		}
	}
	return true;
}