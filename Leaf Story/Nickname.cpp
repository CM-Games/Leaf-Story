#include "Scene.h"

bool nameup()
{
	//�г����� �Է� ����
	//Draw(61, 14, RED, "��������������������������������������������������");
	Draw(63, 16, WHITE, "�г����� �Է����ּ���.");
	//Draw(61, 19, RED, "��������������������������������������������������");
	sprintf(name, "%s%c", name, key);
	Draw(65, 17, WHITE, name);
	if (KeyDown(KEY_ENTER))
		save(CBox, name);
	return true;
}

void save(int sex, char name[256])
{
	FileWrite("info.txt");
	WriteText(name);
	WriteInt(sex);
	FileClose();
	userinfo();
	potion = 2;
	charMP = 100;
	gold = 10000;
	titlemusic(2, 0);
	SceneNumber = MAP_ONE;
}