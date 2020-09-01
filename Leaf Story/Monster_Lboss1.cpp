#include "Scene.h"



bool door(float timeDelta)
{

	if (lastbossdie1 == false)
	{

		Draw(bossX2 + 22, bossY2 - 1, WHITE | BG_BLUE, "[최종보스]");
		Draw(bossX2 + 18, bossY2, WHITE | BG_BLUE, "문 %d/800000", doorHP);
		Draw(bossX2 + 22, bossY2 + 1, YELLOW|BG_BLUE, "########");
		Draw(bossX2 + 19, bossY2 + 2, YELLOW | BG_BLUE, "###   #  #####");
		Draw(bossX2 + 16, bossY2 + 3, YELLOW | BG_BLUE, "###             # ##");
		Draw(bossX2 + 14, bossY2 + 4, YELLOW | BG_BLUE, "##        #          ##");
		Draw(bossX2 + 13, bossY2 + 5, YELLOW | BG_BLUE, "##     ############      #");
		Draw(bossX2 + 11, bossY2 + 6, YELLOW | BG_BLUE, "#     ##     #     ###    ##");
		Draw(bossX2 + 10, bossY2 + 7, YELLOW | BG_BLUE, "##   ##       #       ###    ##");
		Draw(bossX2 + 9, bossY2 + 8, YELLOW | BG_BLUE, "#    ##        #         ##    #");
		Draw(bossX2 + 9, bossY2 + 9, YELLOW | BG_BLUE, "#   ##         #          #    #");
		Draw(bossX2 + 13, bossY2 + 10, YELLOW | BG_BLUE, "#          #          ##    #");
		Draw(bossX2 + 8, bossY2 + 11, YELLOW | BG_BLUE, "#   ##          #           #    #");
		Draw(bossX2 + 8, bossY2 + 12, YELLOW | BG_BLUE, "#   #           #           #    #");
		Draw(bossX2 + 8, bossY2 + 13, YELLOW | BG_BLUE, "#   #           #           #    #");
		Draw(bossX2 + 8, bossY2 + 14, YELLOW | BG_BLUE, "#   #           #           #    #");
		Draw(bossX2 + 8, bossY2 + 15, YELLOW | BG_BLUE, "#   #           #           #    ##");
		Draw(bossX2 + 8, bossY2 + 16, YELLOW | BG_BLUE, "#   #           #           #     #");
		Draw(bossX2 + 7, bossY2 + 17, YELLOW | BG_BLUE, "##   #           #           ##   ##");
		Draw(bossX2 + 7, bossY2 + 18, YELLOW | BG_BLUE, "#    #           #           ##    #");
		Draw(bossX2 + 8, bossY2 + 19, YELLOW | BG_BLUE, "#   #           #           ##   ##");
		Draw(bossX2 + 7, bossY2 + 20, YELLOW | BG_BLUE, "##   #           #           ##    #");
		Draw(bossX2 + 8, bossY2 + 21, YELLOW | BG_BLUE, "#   #           #          ###    #");
		Draw(bossX2 + 8, bossY2 + 22, YELLOW | BG_BLUE, "##################################");
	}



	//몬스터 사망
	if (doorHP != 0)
	{ 
		lastbossdie1 = true;
		}

	return true;
}

