#include "Scene.h"

int RpoX = CharX + 12;
int LpoX = CharX;
bool fire = false;

bool Nomal_Attack_M(float timeDelta)

{	
	// Ä³¸¯ÅÍ°¡ ¿À¸¥ÂÊÀ» º½
		if (charLR == false)
		{	Draw(RpoX, poY, BLUE | BG_SKYBLUE, "¡Ú");	
			RpoX += 1;
			if (to1 == true)
			{
				if (iceX == RpoX)
				{
					xy = false;
					if (monDeath == false)
						iceHP -= rand() % max_attack + mini_attack;
					fire = false;
				}
			}
			else if (to2 == true)
			{
				if (RpoX == munuhX)
				{
					xy = false;
					if (monDeath == false)
						munuhHP -= rand() % max_attack + mini_attack;
					fire = false;
				}
			}
			else if (to3 == true)
			{
				if (RpoX == slimeX+3)
				{
					xy = false;
					if (monDeath == false)
						slimeHP -= rand() % max_attack + mini_attack;
					fire = false;
				}
			}
			else if (toboss == true)
			{
				if (RpoX == bossX1+14)
				{
					xy = false;
					if (bossdie == false)
						donutHP -= rand() % max_attack + mini_attack;
					fire = false;
				}
			}//////////////////////// ¸Ê1 ³¡
			else if (to21 == true)
			{
				if (FBX == RpoX)
				{
					xy = false;
					if (monDeath == false)
						facebookHP -= rand() % max_attack + mini_attack;
					fire = false;
				}
			}
			else if (to22 == true)
			{
				if (stonX == RpoX)
				{
					xy = false;
					if (monDeath == false)
						stonHP -= rand() % max_attack + mini_attack;
					fire = false;
				}
			}
			else if (to23 == true)
			{
				if (fishX == RpoX)
				{
					xy = false;
					if (monDeath == false)
						fishHP -= rand() % max_attack + mini_attack;
					fire = false;
				}
			}
			else if (to2boss == true)
			{
				if (bossX2 == RpoX)
				{
					xy = false;
					if (lastbossdie1 == false)
						doorHP -= rand() % max_attack + mini_attack;
					fire = false;
				}
			}
			if (RpoX > 140)
			{
				xy = false;
				fire = false;
			}
		}

	//Ä³¸¯ÅÍ°¡ ¿ÞÂÊÀ» º½
	if (charLR == true)
	{
		Draw(LpoX, poY, BLUE | BG_SKYBLUE, "¡Ú");
		LpoX -= 1;
		if (to1 == true)
		{
			if (iceX == LpoX)
			{
				xy = false;
				if (monDeath == false)
				iceHP -= rand() % max_attack + mini_attack;
				fire = false;
			}
		}
		else if (to2 == true)
		{
			if (LpoX == munuhX)
			{
				xy = false;
				if (monDeath == false)
				munuhHP -= rand() % max_attack + mini_attack;
				fire = false;
			}
		}
		else if (to3 == true)
		{
			if (LpoX == slimeX+20)
			{
				xy = false;
				if (monDeath == false)
					slimeHP -= rand() % max_attack + mini_attack;
				fire = false;
			}
		}
		else if (toboss == true)
		{
			if (LpoX == bossX1 + 20)
			{
				xy = false;
				if (bossdie == false)
					donutHP -= rand() % max_attack + mini_attack;
				fire = false;
			}
		}//////////////////// ¸Ê 1 ³¡
		else if (to21 == true)
		{
			if (LpoX == FBX + 18)
			{
				xy = false;
				if (monDeath == false)
					facebookHP -= rand() % max_attack + mini_attack;
				fire = false;
			}
		}
		else if (to22 == true)
		{
			if (LpoX == stonX + 18)
			{
				xy = false;
				if (monDeath == false)
					stonHP -= rand() % max_attack + mini_attack;
				fire = false;
			}
		}
		else if (to23 == true)
		{
			if (LpoX == fishX + 16)
			{
				xy = false;
				if (monDeath == false)
					fishHP -= rand() % max_attack + mini_attack;
				fire = false;
			}
		}
		else if (to2boss == true)
		{
			if (LpoX == bossX2+ 25)
			{
				xy = false;
				if (lastbossdie1 == false)
					doorHP -= rand() % max_attack + mini_attack;
				fire = false;
			}
		}
		if (LpoX <= 0)
		{
			xy = false;
			fire = false;
		}
	}

	return true;
}