#include "Scene.h"

bool ice(float timeDelta)
{
	static float monMoveTimer = 0.0f;
	static bool monDirection = true;
	static int monMoveCount = 0;

	Draw(iceX - 1, iceY, BLUE|BG_SKYBLUE, "���� %d/200", iceHP);
	Draw(iceX, iceY + 1, BLUE | BG_BLUE, "������");
	Draw(iceX, iceY + 2, BLUE | BG_BLUE, "������");
	Draw(iceX, iceY + 3, BLUE | BG_BLUE, "������");
	Draw(iceX, iceY + 4, BLUE | BG_BLUE, "������");
	Draw(iceX, iceY + 5, BLUE | BG_BLUE, "������");

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
		if (monDirection == false) iceX -= 1;
		else if (monDirection == true) iceX += 1;
		monMoveTimer = 0.0f;
	}

	//���� ��� ����
	if (iceHP <= 0)
	{
		iceHP = 200;
		monDeath = true;

		goldbox = rand() % 500 + 250;
		if (goldbox > 500) goldbox -= 250;
		gold += goldbox;

		OUTEXP = rand() % 70 + 25;
		if (OUTEXP > 70) OUTEXP -= 25;
		charEXP += OUTEXP;
		OUTEXPTF = true;
	}

	//�������� ������ �˹�
	if (chardie == false)
	{
		if (CharX + 10 == iceX )
		{
			charHP -= rand() % 25 + 10;
			CharX -= 4;
		}
		else if (CharX == iceX + 8)
		{
			charHP -= rand() % 25 + 10;
			CharX += 4;
		}
	}
	return true;
}
