#include "Scene.h"

//���� �������� ��� ��ȣ
int SceneNumber = TITLE_SCENE;

//�ý���
char name[256];//�г���
char readname[256];//�г��� �о�°�
int CBox;//ĳ���͸����-����
bool music= true;
char mapname[256];
bool map1 = true;
bool map2 = true;

int upgradeN = 0; //Now���ۼ�ġ
int upgradeF = 1; //�̷����ۼ�ġ
int upgradeG = 1000; //���ۺ��

//ĳ����
int gold = 5000; //�������
int goldbox = 0; //�������
int sex;//����
int CharX = 6, CharY = 19;//ĳ�� ��ǥ
int charEXP = 0; //���� ����ġ
int charLV = 1; //���� ����
int expbar = 100; //���� �ʿ� ����ġ
int charHP = 100; //���� ü��
int charMP = 100; //���� ����
int OUTEXP;
bool monDeath = false;//��� ����
bool OUTEXPTF = false;//����ġ�α�
bool nomal_attack;// ���� ���
int max_attack=25;//���� �ִ� ���ݷ�
int mini_attack=10;//���� �ּ� ���ݷ�
bool chardie = false;//ĳ���� ��� ����
int max_charHP = 50;//�������� �ִ� ü�� ����
bool charLR = false; //ĳ�� ���� ������ ����
int potion = 2;

//���� ü�� �� ����
int munuhHP = 500;
int slimeHP = 900;
int iceHP = 200;
int donutHP = 5000;
int facebookHP = 3000;
int stonHP = 3500;
int fishHP = 5000;
int doorHP = 800000;
bool monHIT = false;
bool bossdie = false;
bool lastbossdie1 = false;

//���� ��ǥ
int iceX = 80, iceY = 22;
int munuhX = 80, munuhY = 21;
int slimeX = 80, slimeY = 19;
int bossX1 = 40, bossY1 = 7;
int FBX = 80, FBY = 18; 
int stonX = 80, stonY = 20;
int fishX = 80, fishY = 20;
int bossX2 = 50, bossY2 = 5;

//test
//bool askill = false;
//��鼱�� ������ �Լ�
bool SceneRender(float timeDelta)
{
	//��� ��ȣ�� ���� Render ȣ�� ����
	if (SceneNumber == TITLE_SCENE)	return Title_Scene_Render(timeDelta);	
	else if (SceneNumber == EXPLAIN_SCENE) return Explain_Scene_Render(timeDelta);
	else if (SceneNumber == CHOICE_SCENE) return Choice_Scene_Render(timeDelta);
	else if (SceneNumber == NICKNAME) return nameup();
	else if (SceneNumber == CONTINUE_SCENE) return Continue_Scene_Render(timeDelta);
	else if (SceneNumber == MAP_ONE) return map1to1(timeDelta);
	else if (SceneNumber == MAP_TWO) return map1to2(timeDelta);
	else if (SceneNumber == MAP_THREE) return map1to3(timeDelta);
	else if (SceneNumber == MAP_BOSS) return map1toboss(timeDelta);
	else if (SceneNumber == MENU_SCENE) return menu(timeDelta);
	else if (SceneNumber == UPGRADE) return upgrade_w(timeDelta);
	else if (SceneNumber == SHOP) return shop_render(timeDelta);
	else if (SceneNumber == MAP_TWO_ONE) return map2to1(timeDelta);
	else if (SceneNumber == MAP_TWO_TWO) return map2to2(timeDelta);
	else if (SceneNumber == MAP_TWO_THREE) return map2to3(timeDelta);
	else if (SceneNumber == MAP_TWO_BOSS) return map2boss(timeDelta);

	return true;
}
