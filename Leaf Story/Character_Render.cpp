#include "Scene.h"
float motimer = 0.0f; //모션 타이머
float lvtimer = 0.0f; //렙업 이팩트 타이머
float dietimer = 6.0f; //부활 타이머
float potimer = 0.0f; //포션 이펙트
bool lvup = false; //레벨업
bool po = false;
int expbox = 0; //업하고 남은 경치
bool xy = false;
bool Ause = false;
float askillT = 61.0f;

bool Char_Render(float timeDelta)
{
	if (chardie == false)
	{
		if (sex == 1) //남자
		{
			if (charLR == false)
			{
				Draw(CharX + 4, CharY, WHITE, "#######");
				Draw(CharX + 3, CharY + 1, WHITE, "#  #### #");
				Draw(CharX + 3, CharY + 2, WHITE, "# ⊙ ⊙ #");
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
				Draw(CharX + 3, CharY + 2, WHITE, "# ⊙ ⊙ #");
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
		else if (sex == 2) //여자
		{
			if (charLR == false)
			{
				Draw(CharX + 3, CharY, WHITE, "#########");
				Draw(CharX + 2, CharY + 1, WHITE, "##  #### ##");
				Draw(CharX + 2, CharY + 2, WHITE, "## ⊙ ⊙ ##");
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
				Draw(CharX + 2, CharY + 2, WHITE, "## ⊙ ⊙ ##");
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
		else if (KeyDown(KEY_Z)) //기본 공격
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
		else if (KeyDown(KEY_A)) //베기
		{
			if (Ause == false)
			be_gi(timeDelta);
			Ause = true;
		}
		else if (KeyDown(KEY_ONE)) //포션먹기
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
		else if (KeyDown(KEY_ESC)) //메뉴
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
		Draw(CharX , CharY - 2, RED | BG_SKYBLUE, "+++체력회복+++");

		if (potimer >= 1.5) po = false;
	}


	//레벨업 관련
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

	//캐릭터 사망
	if (charHP <= 0)
	{
		dietimer -= timeDelta;
		charHP = 0;
		chardie = true;
		Draw(CharX, CharY + 1, GARY|BG_SKYBLUE, "   ____________");
		Draw(CharX, CharY + 2, GARY | BG_SKYBLUE, "  /            ＼");
		Draw(CharX, CharY + 3, GARY | BG_SKYBLUE, " │    사망    │");
		Draw(CharX, CharY + 4, GARY | BG_SKYBLUE, " │ 경험치100↓│");
		Draw(CharX, CharY + 5, GARY | BG_SKYBLUE, " │   %d초후    │",(int)dietimer);
		Draw(CharX, CharY + 6, GARY | BG_SKYBLUE, " │    부활    │");
		Draw(CharX, CharY + 7, GARY | BG_SKYBLUE, " │            │");
		Draw(CharX, CharY + 8, GARY | BG_SKYBLUE, "┌───────┐");
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
	
	//시간 중첩
	motimer += timeDelta;
	potimer += timeDelta;
	
	//공격 모션
	if (motimer > 0.5)
	{
		nomal_attack = false;
		motimer = 0.0f;
	}

	//발사
	if (fire == true)
	{
		Nomal_Attack_M(timeDelta);
	}

	//레벨업 이펙트
	if (lvup == true)
	{
		lvtimer += timeDelta;
		Draw(CharX + 4, CharY - 3, BLUE|BG_SKYBLUE, "공격력↑");
		Draw(CharX - 2, CharY - 2, BLUE | BG_SKYBLUE, "체력↑ 필요경험치↑");
		Draw(CharX + 2, CharY - 1, BLUE | BG_SKYBLUE, "★레벨업★");
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