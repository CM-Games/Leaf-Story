#include "Scene.h"

int Title_Position = 0;


System*			pSystem;
Sound*			pSound[10];
Channel*		pChannel[10];


bool Title_Scene_Render(float timeDelta)
{

	if (music == true)
	{
		titlemusic(1,0.2); //Ÿ�渣 ��	
		music =false;
	}

	int PosX = 0, PosY = 1;
		//������
	Draw(PosX, PosY, GREEN, "                                                              eu");
	Draw(PosX, PosY + 1, GREEN, "                                                              e");
	Draw(PosX, PosY + 2, GREEN, "                                               ,KyWK,        G");
	Draw(PosX, PosY + 3, GREEN, "                                            WzzDXXXDzD#X,   ,e");
	Draw(PosX, PosY + 4, GREEN, "                                          eEXyWWyyyWWy5XXD  e");
	Draw(PosX, PosY + 5, GREEN, "                                        ,D5WyyyWKyWy5yy5y#eeeuXu");
	Draw(PosX, PosY + 6, GREEN, "                                      uezyKWKKuKKWWyyWWKKz#XD##D#X");
	Draw(PosX, PosY + 7, GREEN, "                                      ,DKWWyyKuKyD5X5yy zeED5KWWyXE,");
	Draw(PosX, PosY + 8, GREEN, "                                     yzyy55yW5XzDzzDX5D#eD9#yKKyKW55u");
	Draw(PosX, PosY + 9, GREEN, "                                    z#X5WWWyWyK,,K, ,  e#5,KXWWWWKKyD");
	Draw(PosX, PosY + 10, GREEN, "                                    XyWyWKKKuWXDDzX5u5eeEEWu5XWWKyWKD");
	Draw(PosX, PosY + 11, GREEN, "                                   WzWWWK,,uWWK Kyu 5eGX5KuuWDuKK5KKDu");
	Draw(PosX, PosY + 12, GREEN, "                                    5Ky,u5XKWyKKKu EeEz,D#,uuXyuK5KyWK");
	Draw(PosX, PosY + 13, GREEN, "                                   X5KXKDKKWyKWXy DeX e ,EuK,y5uWWWX5e");
	Draw(PosX, PosY + 14, GREEN, "                                   zK,yWWyXXXXyuuEeWK euu#5K 5XuKW5Xy");
	Draw(PosX, PosY + 15, GREEN, "                                   W55WKWXyuKK,uDEX KK9uuX5WKDyKKWuyu");
	Draw(PosX, PosY + 16, GREEN, "                                   K5yuWyWKy5uuz,zDKyy5WW9yu,DuKWWWX");
	Draw(PosX, PosY + 17, GREEN, "                                   uyWWW5W5WKy9y GWWWuXKuXy,u5,KWz y");
	Draw(PosX, PosY + 18, GREEN, "                                   yzWKuWyyKW#yuKEWy5uXK,Xy,uXy5Xy");
	Draw(PosX, PosY + 19, GREEN, "                                    WyKuKuKyXWKWyXKKWyXyX#yK55X z");
	Draw(PosX, PosY + 20, GREEN, "                                    yGuWuyXX5yKuXyWK,#W5zW,WyW");
	Draw(PosX, PosY + 21, GREEN, "                                     zKWKyXuDuKu#,KWDDWyKWXz5");
	Draw(PosX, PosY + 22, GREEN, "                                     95uKX ,X uK5uuuzXyEKK ,");
	Draw(PosX, PosY + 23, GREEN, "                                     #WWXKKKyWKXXyDeE");
	Draw(PosX, PosY + 24, GREEN, "                                     zKXy5zzzyzEu  ,");
	Draw(PosX, PosY + 25, GREEN, "                                     #eGDXK");
	Draw(PosX, PosY + 26, GREEN, "                                     5");

	// LEAF STORY
	Draw(PosX, PosY + 28, GREEN, "        #      E#eeeW     WK     u#Eeee       uGe9 yeGDD#ee    Eey     y#EeX   XK      e");
	Draw(PosX, PosY + 29, GREEN, "       5e      e WWX     Kee     ee WWX     ,ezyye ,5,ye W5 GeeXyeee   ee yDeD  ez    e9");
	Draw(PosX, PosY + 30, GREEN, "        e      e         e  e    ez         ee         e    e      ee  e    Xe   eE  e,");
	Draw(PosX, PosY + 31, GREEN, "        e      e9eee    e,  ee   eeeeee      XeeG      e   ee       e  eeGeee     eee");
	Draw(PosX, PosY + 32, GREEN, "        e      e       5eWE9Ke   e9             ye     e   ee       e  eX  eK      e");
	Draw(PosX, PosY + 33, GREEN, "       ,e      e       e  WW  e  ee              e9    e    e#     eK  e5   eu     e");
	Draw(PosX, PosY + 34, GREEN, "       Weeeee  eeeeee eW      ee ee         eeeeeE    ,e     eeeeee    e9    e     e");

	//���� �ɼ�
	Draw(PosX + 105, PosY + 13, WHITE, "��������������������������������");
	Draw(PosX + 105, PosY + 14, WHITE, "��");
	Draw(PosX + 105, PosY + 15, WHITE, "��");
	Draw(PosX + 105, PosY + 16, WHITE, "��");
	Draw(PosX + 105, PosY + 17, WHITE, "��");
	Draw(PosX + 105, PosY + 18, WHITE, "��");
	Draw(PosX + 105, PosY + 19, WHITE, "��");
	Draw(PosX + 105, PosY + 20, WHITE, "��");
	Draw(PosX + 105, PosY + 21, WHITE, "��");
	Draw(PosX + 105, PosY + 22, WHITE, "��");
	Draw(PosX + 121, PosY + 14, WHITE, "��");
	Draw(PosX + 121, PosY + 15, WHITE, "��");
	Draw(PosX + 121, PosY + 16, WHITE, "��");
	Draw(PosX + 121, PosY + 17, WHITE, "��");
	Draw(PosX + 121, PosY + 18, WHITE, "��");
	Draw(PosX + 121, PosY + 19, WHITE, "��");
	Draw(PosX + 121, PosY + 20, WHITE, "��");
	Draw(PosX + 121, PosY + 21, WHITE, "��");
	Draw(PosX + 121, PosY + 22, WHITE, "��");
	Draw(PosX + 112, PosY + 15, WHITE, "���ν���");
	Draw(PosX + 112, PosY + 17, WHITE, "�̾��ϱ�");
	Draw(PosX + 112, PosY + 19, WHITE, "���ӹ��");
	Draw(PosX + 112, PosY + 21, WHITE, "��������");
	Draw(PosX + 105, PosY + 23, WHITE, "��������������������������������");

	//ȭ��ǥ ��ġ
	if (Title_Position == 0)
		Draw(PosX + 108, PosY + 15, WHITE, "��");
	else if (Title_Position == 1)
		Draw(PosX + 108, PosY + 17, WHITE, "��");
	else if (Title_Position == 2)
		Draw(PosX + 108, PosY + 19, WHITE, "��");
	else if (Title_Position == 3)
		Draw(PosX + 108, PosY + 21, WHITE, "��");

	//ȭ��ǥ ������
	if (KeyDown(KEY_UP))
	{
		if (Title_Position == 0)
			Title_Position = 3;
		else if (Title_Position == 1)
			Title_Position = 0;
		else if (Title_Position == 2)
			Title_Position = 1;
		else if (Title_Position == 3)
			Title_Position = 2;
	}
	else if (KeyDown(KEY_DOWN))
	{
		if (Title_Position == 0)
			Title_Position = 1;
		else if (Title_Position == 1)
			Title_Position = 2;
		else if (Title_Position == 3)
			Title_Position = 0;
		else if (Title_Position == 2)
			Title_Position = 3;
	}

	//ȭ��ǥ ���
	if (KeyDown(KEY_ENTER))
	{
		if (Title_Position == 0)
		{
			SceneNumber = CHOICE_SCENE;
			Choice_Reset();
		}
		else if (Title_Position == 1)
		{
			titlemusic(2,0);
			SceneNumber = CONTINUE_SCENE;
			
		}
		else if (Title_Position == 2)
		{
			titlemusic(2,0);
			SceneNumber = EXPLAIN_SCENE;
		}
		else if (Title_Position == 3)
			return false;
	}
	return true;
}

void titlemusic(int x, float sound)
{
	//���� �ý����� ����
	System_Create(&pSystem);
	//	���� �ý��� �⺻ ����
	pSystem->init(10, FMOD_INIT_NORMAL, NULL);

	//	�������� ����
	pSystem->createSound(
		"music\\title.mp3",	//	�������ϰ��
		FMOD_HARDWARE,	//	�������Ͽɼ�
		NULL,			//	Ȯ�嵥����(��������)
		&pSound[0]);	//	������ ���� ������

	pSystem->createSound(
		"music\\��ȭ.wav",
		FMOD_LOOP_OFF | FMOD_HARDWARE,
		NULL,
		&pSound[1]);

	pSystem->createSound(
		"music\\����.mp3",
		FMOD_LOOP_OFF | FMOD_HARDWARE,
		NULL,
		&pSound[2]);

	pSystem->createSound(
		"music\\����.mp3",
		FMOD_LOOP_OFF | FMOD_HARDWARE,
		NULL,
		&pSound[3]);

	pSystem->createSound(
		"music\\����.mp3",
		FMOD_LOOP_OFF | FMOD_HARDWARE,
		NULL,
		&pSound[4]);

	pSystem->createSound(
		"music\\�δ���.mp3",
		FMOD_LOOP_OFF | FMOD_HARDWARE,
		NULL,
		&pSound[5]);

	pSystem->createSound(
		"music\\����.mp3",
		FMOD_LOOP_OFF | FMOD_HARDWARE,
		NULL,
		&pSound[6]);


	if (x == 1) //Ÿ��Ʋ �뷡 ���
	{
		pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[0], false, &pChannel[0]);
		pChannel[0]->setVolume(sound);
	}
	else if (x == 2) //Ÿ��Ʋ �ߴ�
	{
		pChannel[0]->stop();
	}////////////////////////////
	else if (x == 3)//��ȭ�� ���
	{
		pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[1], false, &pChannel[1]);
		pChannel[1]->setVolume(sound);

	}
	else if (x == 4) //��ȭ�� �ߴ�
	{
		pChannel[1]->stop();
	}////////////////////////
	else if (x == 5)//��ȭ����
	{
		pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[2], false, &pChannel[2]);
		pChannel[2]->setVolume(sound);

	}
	else if (x == 6) //��ȭ����
	{
		pChannel[2]->stop();
	}/////////////////////////
	else if (x == 7)//��ȭ����
	{
		pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[3], false, &pChannel[3]);
		pChannel[3]->setVolume(sound);

	}
	else if (x == 8) //��ȭ����
	{
		pChannel[3]->stop();
	}///////////////////////
	else if (x == 9)//�������
	{
		pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[4], false, &pChannel[4]);
		pChannel[4]->setVolume(sound);

	}
	else if (x == 10) //��������
	{
		pChannel[4]->stop();
	}///////////////////////
	else if (x == 11)//�δ��� ���
	{
		pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[5], false, &pChannel[5]);
		pChannel[5]->setVolume(sound);

	}
	else if (x == 12) //�δ�������
	{
		pChannel[5]->stop();
	}///////////////////////	
	else if (x == 13)//���� ���
	{
		pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[6], false, &pChannel[6]);
		pChannel[6]->setVolume(sound);

	}
	else if (x == 14) //��������
	{
		pChannel[6]->stop();
	}///////////////////////	
	else if (x == 50)
	{
		//	�������� ����
		pSound[0]->release();
		pSound[1]->release();
		pSound[2]->release();
		pSound[3]->release();
		pSound[4]->release();
		pSound[5]->release();
		pSound[6]->release();

		//	�ý��� ����
		pSystem->release();
		//	�ý��� �ݱ�
		pSystem->close();
	}
}