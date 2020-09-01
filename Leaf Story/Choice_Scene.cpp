#include "Scene.h"


int CMap[24][30];//캐릭터 틀 표현
char CColor, CColor2;//캐릭터 틀 색깔

void Choice_Reset()
{
	CColor = YELLOW;
	CColor2 = WHITE;
	CBox = 1;
}

bool Choice_Scene_Render(float timeDelta)
{
	Draw(64, 2, WHITE, "캐릭터를 선택해주세요");

	//입력 완료
	if (KeyDown(KEY_ENTER))
	{
		SceneNumber = NICKNAME;
	}
	else if (KeyDown(KEY_RIGHT))
	{
		CColor = WHITE;
		CColor2 = YELLOW;
		CBox = 2;
	}
	else if (KeyDown(KEY_LEFT))
	{
		CColor2 = WHITE;
		CColor = YELLOW;
		CBox = 1;
	}

	//캐릭터 남녀 표현
	male_Render();
	female_Render();

	//캐릭텨 틀 표현
	int PosX = 20, PosY = 5;
	
	FileRead("CMap.txt");

	//1번 틀
	for (int y = 0; y < 30; y++)
	{
		for (int x = 0; x < 24; x++)
		{
			ReadInt(&CMap[x][y]);
			//0 = 없음
			if (CMap[x][y] == 0) Draw((x*2)+PosX , y+PosY, WHITE, "");
			//1 = 벽 생성
			else if (CMap[x][y] == 1) Draw((x * 2) + PosX, y + PosY, CColor, "■");
					}
	}
	
	//2번 틀
	PosX = 80;
	for (int y = 0; y < 30; y++)
	{
		for (int x = 0; x < 24; x++)
		{
			ReadInt(&CMap[x][y]);
			//0 = 없음
			if (CMap[x][y] == 0) Draw((x * 2) + PosX, y + PosY, WHITE, "");
			//1 = 벽 생성
			else if (CMap[x][y] == 1) Draw((x * 2) + PosX, y + PosY, CColor2, "■");
		}
	}

	FileClose();

	Draw(38, PosY + 31, WHITE, "┏━━━━━┓");
	Draw(38, PosY + 32, WHITE, "┃ 남자┃");
	Draw(38, PosY + 33, WHITE, "┗━━━━━┛");

	Draw(111, PosY + 31, WHITE, "┏━━━━━┓");
	Draw(106, PosY + 32, WHITE, "┃ 여자┃");
	Draw(111, PosY + 33, WHITE, "┗━━━━━┛");

	return true;
}

void male_Render()
{
	int PosX = 20, PosY = 6;
	Draw(PosX, PosY + 2, WHITE, "                ############");
	Draw(PosX, PosY + 3, WHITE, "            ####            ###");
	Draw(PosX, PosY + 4, WHITE, "          ##    ######         ###");
	Draw(PosX, PosY + 5, WHITE, "        ##  ###            ## ## ##");
	Draw(PosX, PosY + 6, WHITE, "       ##        #####       ##   #");
	Draw(PosX, PosY + 7, WHITE, "       #     ##           ## #     #");
	Draw(PosX, PosY + 8, WHITE, "        ##          ######### # #  #");
	Draw(PosX, PosY + 9, WHITE, "         #################     #   #");
	Draw(PosX, PosY + 10, WHITE, "       #   #                    ## #");
	Draw(PosX, PosY + 11, WHITE, "        # #                      ##### ");
	Draw(PosX, PosY + 12, WHITE, "          #    ●         ●      #  ##");
	Draw(PosX, PosY + 13, WHITE, "         ##                      #####");
	Draw(PosX, PosY + 14, WHITE, "         #           ▼           #");
	Draw(PosX, PosY + 15, WHITE, "          #                     #");
	Draw(PosX, PosY + 16, WHITE, "          ##        -----      #");
	Draw(PosX, PosY + 17, WHITE, "            ##              ###");
	Draw(PosX, PosY + 18, WHITE, "              ####       ###");
	Draw(PosX, PosY + 19, WHITE, "                  #######  # ");
	Draw(PosX, PosY + 20, WHITE, "                #### ## #####");
	Draw(PosX, PosY + 21, WHITE, "               ## ########## ##");
	Draw(PosX, PosY + 22, WHITE, "              ## ######### #  #");
	Draw(PosX, PosY + 23, WHITE, "            ### ## ####### ##  ##");
	Draw(PosX, PosY + 24, WHITE, "                #############");
	Draw(PosX, PosY + 25, WHITE, "                   ####### ");
	Draw(PosX, PosY + 26, WHITE, "                 # #      # #");
	Draw(PosX, PosY + 27, WHITE, "                ###       ###");
}
          
void female_Render()
{
	int PosX = 83, PosY = 8;
	Draw(PosX, PosY, WHITE, "                   ###########");
	Draw(PosX, PosY+1, WHITE, "              ### #### #   #####");
	Draw(PosX, PosY + 2, WHITE, "            ##  #  ## #  #  ######");
	Draw(PosX, PosY + 3, WHITE, "           ## ##  ### ## ### ######");
	Draw(PosX, PosY + 4, WHITE, "          ## ### ## # ###############");
	Draw(PosX, PosY + 5, WHITE, "          #  #########################");
	Draw(PosX, PosY + 6, WHITE, "         ########             #######");
	Draw(PosX, PosY + 7, WHITE, "          ##                       ####");
	Draw(PosX, PosY + 8, WHITE, "        ##       ●         ●     ## #");
	Draw(PosX, PosY + 9, WHITE, "         #                        ## #");
	Draw(PosX, PosY + 10, WHITE, "       # ##           ▼           ####");
	Draw(PosX, PosY + 11, WHITE, "       ####                      #####");
	Draw(PosX, PosY + 12, WHITE, "       #####         ----       ###  #");
	Draw(PosX, PosY + 13, WHITE, "       #  ###                 ####   #");
	Draw(PosX, PosY + 14, WHITE, "      ### #######         ####   # ## #");
	Draw(PosX, PosY + 15, WHITE, "      # ###       # ######        ####");
	Draw(PosX, PosY + 16, WHITE, "      # ##          ##   ###       ##");
	Draw(PosX, PosY + 17, WHITE, "      ## ##       ############   #####");
	Draw(PosX, PosY + 18, WHITE, "      #####     ## # #### #  ##  # ###");
	Draw(PosX, PosY + 19, WHITE, "               ##  # #### #   #");
	Draw(PosX, PosY + 20, WHITE, "              #   ## ###  ##   #");
	Draw(PosX, PosY + 21, WHITE, "                   #########");
	Draw(PosX, PosY + 22, WHITE, "                   #       #");
	Draw(PosX, PosY + 23, WHITE, "                  ##       ##");
	Draw(PosX, PosY + 24, WHITE, "                 ###        ##");
}
                                            