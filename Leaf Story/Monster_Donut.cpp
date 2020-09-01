#include "Scene.h"

bool A1use = true; //1번패턴
bool A1up = true; //1번 패턴
float bossA1Timer = 0.0f; //1번 패턴
float bossA1MTimer = 0.0f; //1번패턴 움직임
int A1X; //1번 패턴
bool A1 = true;  //1번 패턴
float bossattack = 0.0f; // 보스 공격 주기


bool donut(float timeDelta)
{

	if (bossdie == false)
	{
		bossA1Timer += timeDelta;
		bossA1MTimer += timeDelta;
		bossattack += timeDelta;

		Draw(bossX1 + 22, bossY1 - 1, RED | BG_SKYBLUE, "[보스]");
		Draw(bossX1 + 16, bossY1, RED | BG_SKYBLUE, "도넛 %d/5000", donutHP);
		Draw(bossX1 + 19, bossY1 + 1, PURPLE, "############");
		Draw(bossX1 + 16, bossY1 + 2, PURPLE, "####          ####");
		Draw(bossX1 + 14, bossY1 + 3, PURPLE, "###                 ###");
		Draw(bossX1 + 12, bossY1 + 4, PURPLE, "##                      ##");
		Draw(bossX1 + 11, bossY1 + 5, PURPLE, "##       ⊙      ⊙        ##");
		Draw(bossX1 + 10, bossY1 + 6, PURPLE, "##                           #");
		Draw(bossX1 + 9, bossY1 + 7, PURPLE, "##          ########           #");
		Draw(bossX1 + 9, bossY1 + 8, PURPLE, "#         ###      ###         ##");
		Draw(bossX1 + 8, bossY1 + 9, PURPLE, "##        ##          ##         #");
		Draw(bossX1 + 8, bossY1 + 10, PURPLE, "##        #            #         #");
		Draw(bossX1 + 8, bossY1 + 11, PURPLE, "##        #            #         #");
		Draw(bossX1 + 8, bossY1 + 12, PURPLE, "##        #           ##         #");
		Draw(bossX1 + 9, bossY1 + 13, PURPLE, "#         #         ##         ##");
		Draw(bossX1 + 9, bossY1 + 14, PURPLE, "##         ####  ####          #");
		Draw(bossX1 + 10, bossY1 + 15, PURPLE, "#            ####            ##");
		Draw(bossX1 + 11, bossY1 + 16, PURPLE, "#                          ##");
		Draw(bossX1 + 12, bossY1 + 17, PURPLE, "##                      ###");
		Draw(bossX1 + 13, bossY1 + 18, PURPLE, "###                  ###");
		Draw(bossX1 + 15, bossY1 + 19, PURPLE, "####            ####");
		Draw(bossX1 + 18, bossY1 + 20, PURPLE, "##############");

		if (bossattack > 5)
			A1use = true;

		if (chardie == false)
		{
			//보스 1번 패턴 : 내려찍기
			if (A1use == true)
			{
				if (A1 == true)	A1X = CharX;

				if (bossA1Timer > 4.0)
				{
					A1 = false;
					if (bossA1MTimer > 0.1)
					{
						if (A1up == true)
						{
							if (bossY1 >= 2)
								bossY1 -= 3;
							else A1up = false;
						}
						else if (A1X < bossX1 && bossX1 != A1X - 16)
							bossX1 -= 2;
						else if (A1X > bossX1 && bossX1 != A1X - 16)
							bossX1 += 2;
						else if (A1X - 20 <= bossX1 && bossX1 <= A1X - 10 || A1X == bossX1)
						{
							if (bossY1 != 7)
								bossY1 += 3;
							else
							{
								if (bossX1 + 8 <= CharX && CharX <= bossX1 + 41)
									charHP -= 200;

								bossA1Timer = 0.0f;
								A1 = true;
								A1use = false;
								A1up = true;
							}
						}
					}
				}
			}
		}
	}
		
	
	
	//몬스터 사망
	if (donutHP <= 0)
	{		
		charEXP += 5000;
		gold += 50000;
		bossdie = true;
		donutHP = 5000;
	}
	return true;
}