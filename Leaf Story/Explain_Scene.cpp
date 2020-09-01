#include "Scene.h"

bool Explain_Scene_Render(float timeDelta)
{
	Draw(53, 14, WHITE, "┌──────────────────┐");
	Draw(55, 15, WHITE, "아주 이~지 한 게임이니 직접 해보세요.");
	Draw(55, 16, WHITE, "             나가기 - 엔터           ");
	Draw(53, 17, WHITE, "└──────────────────┘");


	if (KeyDown(KEY_ENTER))
	{
		SceneNumber = TITLE_SCENE;
		music = true;
	}

	return true;
}