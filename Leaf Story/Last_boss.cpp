#include "Scene.h"

bool to2boss = true;

bool map2boss(float timeDelta)
{
	int Map[72][31] = { 0 };

	FileRead("Map2-boss.txt");
	int PosX = 0, PosY = 0;

	//1�� Ʋ

	for (int y = 0; y < 31; y++)
	{
		for (int x = 0; x < 72; x++)
		{
			ReadInt(&Map[x][y]);
			//0 = ����
			if (Map[x][y] == 0) Draw((x * 2) + PosX, y + PosY, BLUE | BG_BLUE, "  ");
			//1 or 2 = �� ����
			else if (Map[x][y] == 1) Draw((x * 2) + PosX, y + PosY, WHITE | BG_WHITE, "��");
			else if (Map[x][y] == 2) Draw((x * 2) + PosX, y + PosY, GREEN | BG_GREEN, "��");
			//3-��Ż
			else if (Map[x][y] == 3) Draw((x * 2) + PosX, y + PosY, PURPLE | BG_PURPLE, "��");
		}

	}

	FileClose();
	mapnumber2(6, "���� ����");
	userinfo_Render();
	skill();


	if (lastbossdie1 == false)
		door(timeDelta);
	else
	{
		Draw(60, 13, RED | BG_BLUE, "���� ���� Ŭ����~!");
		Draw(60, 14, RED | BG_BLUE, "���ݱ��� �̿����ּż� �����մϴ�");

				Draw(60, 15, RED | BG_BLUE, "���� ü������ ����Ǿ����ϴ�.");
				Draw(60, 16, RED | BG_BLUE, "�� �ϽǷ��� ���� ���ּ���.");
		
	}



	Char_Render(timeDelta);


	LOG(timeDelta);

	return true;
}
