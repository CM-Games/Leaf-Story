#include "Scene.h"

bool Explain_Scene_Render(float timeDelta)
{
	Draw(53, 14, WHITE, "����������������������������������������");
	Draw(55, 15, WHITE, "���� ��~�� �� �����̴� ���� �غ�����.");
	Draw(55, 16, WHITE, "             ������ - ����           ");
	Draw(53, 17, WHITE, "����������������������������������������");


	if (KeyDown(KEY_ENTER))
	{
		SceneNumber = TITLE_SCENE;
		music = true;
	}

	return true;
}