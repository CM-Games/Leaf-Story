#include "Scene.h"

int upposition = 0; //ȭ��ǥ ��ġ
int upnumber = 0; //Ȯ�� ����
bool upresult = false; //����/���� �Ǻ�
bool upuse = true;//��� ���� �Ǻ�
int mini = 3; //���۽� �������ݷ�
int max = 3;//���۽� �������ݷ�
bool maxupgreade = false; //���׷��̵� ��
float uptimer = 0.0f; //����Ÿ��
bool booltimer = false; //Ÿ�̸Ӹ� ���ؼ�

bool upgrade_w(float timeDelta)
{
	uptimer += timeDelta;
	static int upX = 40, upY = 8;
	//Draw(upX, upY, WHITE, "����������������������������������������������������������������������������������������������������������");
	//Draw(upX, upY + 1, WHITE, "��               [    ��    ��   ��   ȭ   ]              ��");
	//Draw(upX, upY + 2, WHITE, "����������������������������������������������������������������������������������������������������������");
	//Draw(upX, upY + 3, WHITE, "��                                                        ��");
	//Draw(upX, upY + 4, WHITE, "��                                                        ��");
	//Draw(upX, upY + 5, WHITE, "��                                                        ��");
	//Draw(upX, upY + 6, WHITE, "��                                                        ��");
	//Draw(upX, upY + 7, WHITE, "��                                                        ��");
	//Draw(upX, upY + 8, WHITE, "��                                                        ��");
	//Draw(upX, upY + 9, WHITE, "��                                                        ��");
	//Draw(upX, upY + 10, WHITE, "��                                                        ��");
	//Draw(upX, upY + 11, WHITE, "��                                                        ��");
	//Draw(upX, upY + 12, WHITE, "��                                                        ��");
	//Draw(upX, upY + 13, WHITE, "��                                                        ��");
	//Draw(upX, upY + 14, WHITE, "��                                                        ��");
	//Draw(upX, upY + 15, WHITE, "��                                                        ��");
	//Draw(upX, upY + 16, WHITE, "��                                                        ��");
	//Draw(upX, upY + 17, WHITE, "��                                                        ��");
	//Draw(upX, upY + 18, WHITE, "��                                                        ��");
	//Draw(upX, upY + 19, WHITE, "��                                                        ��");
	//Draw(upX, upY + 20, WHITE, "��                                                        ��");
	//Draw(upX, upY + 21, WHITE, "��                                                        ��");
	//Draw(upX, upY + 22, WHITE, "������������������������������������������������������������");
	Draw(upX + 16, upY + 3, YELLOW, "��带 ����Ͽ� ��ȭ�� �մϴ�.");

	if (upgradeN <= 15)
	{
		Draw(upX + 4, upY + 8, YELLOW, "       ��ȭ ��       ");
		Draw(upX + 8, upY + 10, WHITE, "��ȭ ��ġ : +%d", upgradeN);
		Draw(upX + 7, upY + 11, WHITE, "��ȭ ��� : %d", upgradeG);
		Draw(upX + 7, upY + 12, WHITE, "���� ��� : %d", gold);
		Draw(upX + 10, upY + 14, WHITE, "���� ���ݷ�");
		Draw(upX + 12, upY + 15, WHITE, "%d ~ %d", mini_attack, max_attack);
		//Draw(upX + 4, upY + 16, YELLOW, "��                   ��");

		Draw(upX + 29, upY + 12, WHITE, "��");


		Draw(upX + 32, upY + 8, RED, "       ��ȭ ��       ");
		Draw(upX + 36, upY + 10, RED, "��ȭ ��ġ : +%d", upgradeN + 1);
		Draw(upX + 35, upY + 11, YELLOW, "��ȭ ��� : %d", upgradeG);
		Draw(upX + 35, upY + 12, YELLOW, "���� ��� : %d", gold - upgradeG);
		Draw(upX + 36, upY + 14, YELLOW, "��ȭ �� ���ݷ�");
		Draw(upX + 40, upY + 15, RED, "%d ~ %d", mini_attack + mini, max_attack + max);
		//Draw(upX + 32, upY + 16, RED, "��                   ��");

		hakprint();
	}
	else
	{
		Draw(upX + 19, upY + 8, YELLOW, "       �ִ� ��ȭ       ");
		Draw(upX + 25, upY + 11, RED, "��ȭ ��ġ : +%d", upgradeN);
		Draw(upX + 26, upY + 13, RED, "���� ���ݷ�");
		Draw(upX + 28, upY + 14, RED, "%d ~ %d", mini_attack, max_attack);
	//	Draw(upX + 19, upY + 16, YELLOW, "��                     ��");
		maxupgreade = true;
	}

	//ȭ��ǥ ��ġ ����
	if (upposition == 0)
		Draw(upX + 13, upY + 21, WHITE, "��");
	if (upposition == 1)
		Draw(upX + 38, upY + 21, WHITE, "��");
	if (upposition == 3)
		Draw(upX + 26, upY + 21, WHITE, "��");


	if (KeyDown(KEY_ENTER))
	{
		if (upposition == 0)
		{
			booltimer = true;
			uptimer = 0.0f;
		}

		else if (upposition == 1 || upposition == 3)
			SceneNumber = MENU_SCENE;
	}

	//2�ʵ��� ����Ʈ
	if (booltimer == true)
	{
		if (upuse == true)
		{
			if (uptimer <= 1.5)
			{
				Draw(upX - 6, upY + 10, WHITE | BG_WHITE, "��������������������������������������");
				Draw(upX - 6, upY + 11, WHITE | BG_WHITE, "��������������������������������������");
				Draw(upX - 6, upY + 12, WHITE | BG_WHITE, "��������������������������������������");
				Draw(upX - 6, upY + 13, WHITE | BG_WHITE, "��������������������������������������");
				Draw(upX - 6, upY + 14, WHITE | BG_WHITE, "��������������������������������������");
				Draw(upX + 24, upY + 12, RED | BG_WHITE, "�� ȭ �� . . ");

			}
			else
			{
				if (upgradeN == 0)
					upeffect(1);
				else if (upgradeN == 1)
					upeffect(2);
				else if (2 <= upgradeN && upgradeN <= 5)
					upeffect(3);
				else if (6 <= upgradeN && upgradeN <= 10)
					upeffect(4);
				else if (11 <= upgradeN && upgradeN <= 12)
					upeffect(5);
				else if (13 <= upgradeN && upgradeN <= 14)
					upeffect(6);
			}
		}
	}

	//�ִ� ��ȭ�� �ȵǾ�����
	if (maxupgreade == false)
	{
		if (KeyDown(KEY_RIGHT))
			upposition = 1;
		else if (KeyDown(KEY_LEFT))
			upposition = 0;

		//��� �Ǻ�
		if (upgradeN <= 5)
		{
			if (gold - upgradeG < 0) upuse = false;
			else upuse = true;
		}
		else if (5 < upgradeN <= 10)
		{
			if (gold - upgradeG < 0) upuse = false;
			else upuse = true;
		}
		else if (10 < upgradeN <= 15)
		{
			if (gold - upgradeG < 0) upuse = false;
			else upuse = true;
		}

		//��ȭ ������
		if (upresult == true)
		{
			if (upuse == true)
			{
				if (upgradeN <= 5)
				{
					mini_attack += 3;
					max_attack += 3;
					upgradeG += 4000;
					gold -= 4000;
					if (upgradeN == 4)
					{
						mini = 5;
						max = 5;
					}
				}
				else if (5 < upgradeN <= 10)
				{
					mini_attack += 5;
					max_attack += 5;
					upgradeG += 7000;
					gold -= 7000;
					if (upgradeN == 9)
					{
						mini = 20;
						max = 20;
					}
				}
				else if (10 < upgradeN <= 15)
				{
					mini = 20;
					max = 20;
					mini_attack += 20;
					max_attack += 20;
					upgradeG += 10000;
					gold -= 10000;
				}
				titlemusic(7, 1);
				titlemusic(8, 1);
				upgradeN += 1;
				upgradeF += 1;
				upresult = false;
				uptimer = 0.0f;
				booltimer = false;
			}
		}

		if (upuse == false)
		{
			Draw(upX + 19, upY + 19, RED, "[���]     �� �����մϴ�.");
			Draw(upX + 26, upY + 19, YELLOW, "���");
		}
		Draw(upX + 15, upY + 21, WHITE, "��ȭ �ϱ�");
		Draw(upX + 40, upY + 21, WHITE, "������");
	}
	else
	{
		upposition = 3;
		Draw(upX + 28, upY + 21, WHITE, "������");
	}
	return true;
}

void hakprint() //Ȯ������
{
	if (upgradeF == 1)
	{
		Draw(52, 13, GREEN, "����Ȯ�� : 100%%");
		Draw(77, 13, RED, "����Ȯ�� : 0%%");
	}
	else if (upgradeF == 2)
	{
		Draw(52, 13, GREEN, "����Ȯ�� : 90%%");
		Draw(77, 13, RED, "����Ȯ�� : 0%%");
	}
	else if (3<=upgradeF&&upgradeF <=5)
	{
		Draw(52, 13, GREEN, "����Ȯ�� : 70%%");
		Draw(77, 13, RED, "����Ȯ�� : 0%%");
	}
	else if (6 <= upgradeF&&upgradeF <= 10)
	{
		Draw(52, 13, GREEN, "����Ȯ�� : 50%%");
		Draw(77, 13, RED, "����(�϶�)Ȯ�� : 50%%");
	}
	else if (11 <= upgradeF&&upgradeF <= 12)
	{
		Draw(52, 13, GREEN, "����Ȯ�� : 20%%");
		Draw(77, 13, RED, "����(�϶�)Ȯ�� : 80%%");
	}
	else if (13 <= upgradeF&&upgradeF <= 15)
	{
		Draw(52, 13, GREEN, "����Ȯ�� : 5%%");
		Draw(77, 13, RED, "����(�϶�)Ȯ�� : 95%%");
	}
}

void upeffect(int x)
{
	switch (x)
	{
	case 1: //100�� ���� 1
		upresult = true;
		break;
	case 2: //90�� ����	2
		upnumber = rand() % 100 + 1;
		if (upnumber <= 90) upresult = true;
		else
		{
			gold -= upgradeG;
			titlemusic(5, 1);
			titlemusic(6, 1);
		}
		break;

	case 3: //70�� ����3~5
		upnumber = rand() % 100 + 1;
		if (upnumber <= 70) upresult = true;
		else
		{
			gold -= upgradeG;
			titlemusic(5, 1);
			titlemusic(6, 1);
		}
		break;

	case 4: //50�� ���� 6~10
		upnumber = rand() % 100 + 1;
		if (upnumber <= 50) upresult = true;
		else
		{		gold -= upgradeG;
			upgradeN--;	
			titlemusic(5, 1);
			titlemusic(6, 1);
		
		}
		break;

	case 5: //20�� ���� 11 ~ 12
		upnumber = rand() % 100 + 1;
		if (upnumber <= 20) upresult = true;
		else
		{			gold -= upgradeG;
			upgradeN--;
			titlemusic(5, 1);
			titlemusic(6, 1);
		
		}
		break;

	case 6: //5�� ���� 13~15
		upnumber = rand() % 100 + 1;
		if (upnumber <= 5) upresult = true;
		else
		{			gold -= upgradeG;
			upgradeN--;
			titlemusic(5, 1);
			titlemusic(6, 1);
		
		}
		break;

	default:
		break;
	}
}