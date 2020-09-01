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

	//1�� Ʋ

	for (int y = 0; y < 31; y++)
	{
		for (int x = 0; x < 72; x++)
		{
			ReadInt(&Map[x][y]);
			//0 = ����
			if (Map[x][y] == 0) Draw((x * 2) + PosX, y + PosY, SKYBLUE | BG_SKYBLUE, "  ");
			//1 or 2 = �� ����
			else if (Map[x][y] == 1) Draw((x * 2) + PosX, y + PosY, WHITE | BG_WHITE, "��");
			else if (Map[x][y] == 2) Draw((x * 2) + PosX, y + PosY, GREEN | BG_GREEN, "��");
			//3-��Ż
			else if (Map[x][y] == 3) Draw((x * 2) + PosX, y + PosY, PURPLE | BG_PURPLE, "��");

			Draw(26, 14, BLUE | BG_SKYBLUE, "�� ���� ��");
			Draw(70, 14, BLUE | BG_SKYBLUE, "�� ��ȭ ��");
			Draw(113, 14, BLUE | BG_SKYBLUE, "�� ���� ���� ��");
		}

	}
	FileClose();
	mapnumber(5, "���� ������");
	Char_Render(timeDelta);
	userinfo_Render();
	skill();

	//�� ������ ���
	if (KeyDown(KEY_UP))
	{
		if (CharX <= 0) // ���������� ����
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
			//��ȭ
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
	WriteText(readname); //�̸�
	WriteInt(sex);  //����
	WriteInt(charLV); //����
	WriteInt(charEXP); //����ġ
	WriteInt(expbar); //�ʿ����ġ
	WriteInt(mini_attack); // �ּҰ��ݷ�
	WriteInt(max_attack); // �ִ���ݷ�
	WriteInt(charHP); // ä��	
	WriteInt(max_charHP);//�ִ�ü��
	WriteInt(charMP); // ����
	WriteInt(potion); // ���ǰ���
	WriteInt(gold); // ���
	WriteInt(upgradeN); // ���� ���� ��ȭ��ġ
	FileClose();
return false;
}