#include "Scene.h"
float motimer = 0.0f; //��� Ÿ�̸�
float lvtimer = 0.0f; //���� ����Ʈ Ÿ�̸�
float dietimer = 6.0f; //��Ȱ Ÿ�̸�
float potimer = 0.0f; //���� ����Ʈ
bool lvup = false; //������
bool po = false;
int expbox = 0; //���ϰ� ���� ��ġ
bool xy = false;
bool Ause = false;
float askillT = 61.0f;

bool Char_Render(float timeDelta)
{
	if (chardie == false)
	{
		if (sex == 1) //����
		{
			if (charLR == false)
			{
				Draw(CharX + 4, CharY, WHITE, "#######");
				Draw(CharX + 3, CharY + 1, WHITE, "#  #### #");
				Draw(CharX + 3, CharY + 2, WHITE, "# �� �� #");
				Draw(CharX + 3, CharY + 3, WHITE, "#   -   #");
				Draw(CharX + 4, CharY + 4, WHITE, "#     #");
				Draw(CharX + 6, CharY + 5, WHITE, "###");
				Draw(CharX + 5, CharY + 6, WHITE, "#####");
				Draw(CharX + 4, CharY + 7, WHITE, "# ### ");
				Draw(CharX + 6, CharY + 8, WHITE, "###");
				Draw(CharX + 6, CharY + 8, WHITE, "#  #");

				if (nomal_attack == false)
					Draw(CharX + 10, CharY + 7, WHITE, "#");
				else if (nomal_attack == true)
					Draw(CharX + 10, CharY + 6, WHITE, "##");
			}
			else if (charLR == true)
			{
				Draw(CharX + 4, CharY, WHITE, "#######");
				Draw(CharX + 3, CharY + 1, WHITE, "# ####  #");
				Draw(CharX + 3, CharY + 2, WHITE, "# �� �� #");
				Draw(CharX + 3, CharY + 3, WHITE, "#   -   #");
				Draw(CharX + 4, CharY + 4, WHITE, "#     #");
				Draw(CharX + 6, CharY + 5, WHITE, "###");
				Draw(CharX + 5, CharY + 6, WHITE, "#####");
				Draw(CharX + 4, CharY + 7, WHITE, "  ### #");
				Draw(CharX + 6, CharY + 8, WHITE, "###");
				Draw(CharX + 6, CharY + 8, WHITE, "#  #");

				if (nomal_attack == false)
					Draw(CharX + 4, CharY + 7, WHITE, "#");
				else if (nomal_attack == true)
					Draw(CharX + 4, CharY + 6, WHITE, "##");
			}
		}
		else if (sex == 2) //����
		{
			if (charLR == false)
			{
				Draw(CharX + 3, CharY, WHITE, "#########");
				Draw(CharX + 2, CharY + 1, WHITE, "##  #### ##");
				Draw(CharX + 2, CharY + 2, WHITE, "## �� �� ##");
				Draw(CharX + 2, CharY + 3, WHITE, "##   -   ##");
				Draw(CharX + 2, CharY + 4, WHITE, "###     ##");
				Draw(CharX + 6, CharY + 5, WHITE, "###");
				Draw(CharX + 5, CharY + 6, WHITE, "#####");
				Draw(CharX + 4, CharY + 7, WHITE, "# ### ");
				Draw(CharX + 6, CharY + 8, WHITE, "###");
				Draw(CharX + 6, CharY + 8, WHITE, "#  #");

				if (nomal_attack == false)
					Draw(CharX + 10, CharY + 7, WHITE, "#");
				else if (nomal_attack == true)
					Draw(CharX + 10, CharY + 6, WHITE, "##");
			}
			else if (charLR == true)
			{
				Draw(CharX + 3, CharY, WHITE, "#########");
				Draw(CharX + 2, CharY + 1, WHITE, "## ####  ##");
				Draw(CharX + 2, CharY + 2, WHITE, "## �� �� ##");
				Draw(CharX + 2, CharY + 3, WHITE, "##   -   ##");
				Draw(CharX + 2, CharY + 4, WHITE, "###     ##");
				Draw(CharX + 6, CharY + 5, WHITE, "###");
				Draw(CharX + 5, CharY + 6, WHITE, "#####");
				Draw(CharX + 4, CharY + 7, WHITE, "# ### ");
				Draw(CharX + 6, CharY + 8, WHITE, "###");
				Draw(CharX + 6, CharY + 8, WHITE, "#  #");

				if (nomal_attack == false)
					Draw(CharX + 4, CharY + 7, WHITE, "#");
				else if (nomal_attack == true)
					Draw(CharX + 4, CharY + 6, WHITE, "##");
			}
		}


		if (KeyDown(KEY_LEFT))
		{
			charLR = true;
			if (CharX > 0)
				CharX -= 4;
		}
		else if (KeyDown(KEY_RIGHT))
		{
			charLR = false;
			if (CharX != 130)
				CharX += 4;
		}
		else if (KeyDown(KEY_Z)) //�⺻ ����
		{
			if (xy == false)
			{
				if (charLR == false)
					RpoX = CharX + 12;
				else if (charLR == true)
					LpoX = CharX;
				xy = true;
				nomal_attack = true;
				fire = true;
			}
		}
		else if (KeyDown(KEY_A)) //����
		{
			if (Ause == false)
			be_gi(timeDelta);
			Ause = true;
		}
		else if (KeyDown(KEY_ONE)) //���ǸԱ�
		{
			if (potion != 0)
			{

				charHP += max_charHP / 2;
				potion -= 1;
				potimer = 0.0f;
				po = true;
				if (charHP + (max_charHP / 2) > max_charHP)
					charHP = max_charHP;
			}
		}
		else if (KeyDown(KEY_ESC)) //�޴�
		{
			titlemusic(4, 1);
			musicQ = true;
			CharX = 6;
			SceneNumber = MENU_SCENE;
		}
	}

	if (Ause == true)
	{
		askillT -= timeDelta;
		if (askillT <= 0)
			Ause = false;
	}

	if (po == true)
	{	
		Draw(CharX , CharY - 2, RED | BG_SKYBLUE, "+++ü��ȸ��+++");

		if (potimer >= 1.5) po = false;
	}


	//������ ����
	if (charEXP >= expbar)
	{
		expbox += (charEXP - expbar);
		charEXP = expbox;
		charLV++;
		expbar += 50;
		charHP += 50;
		max_charHP += 50;
		max_attack += 30;
		mini_attack +=10;
		expbox = 0;
		lvup = true;
	}
	else if (charEXP < 0)
		charEXP = 0;

	//ĳ���� ���
	if (charHP <= 0)
	{
		dietimer -= timeDelta;
		charHP = 0;
		chardie = true;
		Draw(CharX, CharY + 1, GARY|BG_SKYBLUE, "   ____________");
		Draw(CharX, CharY + 2, GARY | BG_SKYBLUE, "  /            ��");
		Draw(CharX, CharY + 3, GARY | BG_SKYBLUE, " ��    ���    ��");
		Draw(CharX, CharY + 4, GARY | BG_SKYBLUE, " �� ����ġ100�馢");
		Draw(CharX, CharY + 5, GARY | BG_SKYBLUE, " ��   %d����    ��",(int)dietimer);
		Draw(CharX, CharY + 6, GARY | BG_SKYBLUE, " ��    ��Ȱ    ��");
		Draw(CharX, CharY + 7, GARY | BG_SKYBLUE, " ��            ��");
		Draw(CharX, CharY + 8, GARY | BG_SKYBLUE, "������������������");
		if (dietimer <= 0)
		{
			charHP = max_charHP;
			CharX = 6;
			CharY = 19;
			charEXP -= 100;
			dietimer = 6.0;
			chardie = false;
		}
	}
	
	//�ð� ��ø
	motimer += timeDelta;
	potimer += timeDelta;
	
	//���� ���
	if (motimer > 0.5)
	{
		nomal_attack = false;
		motimer = 0.0f;
	}

	//�߻�
	if (fire == true)
	{
		Nomal_Attack_M(timeDelta);
	}

	//������ ����Ʈ
	if (lvup == true)
	{
		lvtimer += timeDelta;
		Draw(CharX + 4, CharY - 3, BLUE|BG_SKYBLUE, "���ݷ¡�");
		Draw(CharX - 2, CharY - 2, BLUE | BG_SKYBLUE, "ü�¡� �ʿ����ġ��");
		Draw(CharX + 2, CharY - 1, BLUE | BG_SKYBLUE, "�ڷ�������");
		if (lvtimer > 1.5)
		{
			lvup = false;
			lvtimer = 0.0f;
		}
	}

	return true;
}


/*               
    #### ##    
  ##   ### #   
   #       #   
   #       ##  
   #           
      ###      
     ######    
   #  ###  #             
      ###   */