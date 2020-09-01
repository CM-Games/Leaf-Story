#include "Scene.h"

bool slime(float timeDelta)
{
	static float monMoveTimer = 0.0f;
	static bool monDirection = true;
	static int monMoveCount = 0;

	Draw(slimeX+4, slimeY, RED|BG_SKYBLUE, "����� %d/900", slimeHP);
	Draw(slimeX+14, slimeY + 1, GREEN2 | BG_SKYBLUE, "######");
	Draw(slimeX+11, slimeY + 2, GREEN2 | BG_SKYBLUE, "###      ##");
	Draw(slimeX+8, slimeY + 3, GREEN2 | BG_SKYBLUE, "##    ##     #");
	Draw(slimeX+5, slimeY + 4, GREEN2 | BG_SKYBLUE, "###        ###    #");
	Draw(slimeX+3, slimeY + 5, GREEN2 | BG_SKYBLUE, "##   ��    ��   ##   ###");
	Draw(slimeX+2, slimeY + 6, GREEN2 | BG_SKYBLUE, "#                 ##   ##");
	Draw(slimeX+3, slimeY + 7, GREEN2 | BG_SKYBLUE, "##              ##");
	Draw(slimeX+4, slimeY + 8, GREEN2 | BG_SKYBLUE, "###############");


	monMoveTimer += timeDelta;

	//���� �̵�
	if (monMoveTimer >= 0.1f)
	{
		monMoveCount += 1;
		if (monMoveCount == 40)
		{
			if (monDirection == false) monDirection = true;
			else if (monDirection == true) monDirection = false;
			monMoveCount = 0;
		}
		if (monDirection == false) slimeX -= 1;
		else if (monDirection == true) slimeX += 1;
		monMoveTimer = 0.0f;
	}

	//���� ��� ����
	if (slimeHP <= 0)
	{
		slimeHP = 900;
		monDeath = true;

		goldbox = rand() % 5000 + 1500;
		if (goldbox > 5000) goldbox -= 1500;
		gold += goldbox;

		OUTEXP = rand() % 500 + 150;
		if (OUTEXP > 500) OUTEXP -= 150;
		charEXP += OUTEXP;
		OUTEXPTF = true;
	}

	//�������� ������ �˹�
	if (chardie == false)
	{
		if (CharX+10 == slimeX)
		{
			charHP -= rand() % 300 + 150;
			CharX -= 4;
		}
		else if (CharX == slimeX + 20)
		{
			charHP -= rand() % 300 + 150;
			if (CharX < 130)
			CharX += 4;
		}
	}

	return true;
}