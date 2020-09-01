#ifndef __SCENE_H__
#define __SCENE_H__
using namespace std;
//Draw / Input ���(h) Include
#include "Draw.h"
#include "Input.h"
#include "FileIO.h"
#include "RemoveBar.h"
#include <Windows.h>
#include <ctime>

//�뷡
#include <conio.h>
#include <iostream>
#include "fmod.hpp"
#pragma	comment (lib, "fmodex_vc.lib")
using namespace FMOD;

//��鼱�� ������ �Լ�
bool SceneRender(float timeDelta);

enum Scene
{
	TITLE_SCENE,EXPLAIN_SCENE,CHOICE_SCENE,NICKNAME,CONTINUE_SCENE,MAP_ONE,MAP_TWO,MAP_THREE,MAP_BOSS,MENU_SCENE,UPGRADE,SHOP,MAP_TWO_ONE, MAP_TWO_TWO, MAP_TWO_THREE,MAP_TWO_BOSS
	
};//Ÿ��Ʋ,����,ĳ���ͼ���,�г�������,�̾��ϱ�
//���� �������� ����ȣ
//extern�� ����ؼ� Scene.cpp�� ������ ����
extern int SceneNumber;
extern int CBox;
extern char name[256];
extern int sex;
extern char readname[256];

//ĳ����
extern int CharX;
extern int CharY;
extern int charEXP;
extern int charLV;
extern int expbar;
extern int charHP;
extern int charMP;
extern bool nomal_attack;
extern int max_attack;
extern int mini_attack;
extern bool chardie;
extern int max_charHP;
extern bool charLR;
extern int potion;

//���� 
extern int munuhHP;
extern int slimeHP;
extern int iceHP;
extern int donutHP;
extern int facebookHP;
extern int stonHP;
extern int fishHP;
extern int doorHP;
extern bool monDeath;//���� ���� üũ
extern bool monHIT;
extern bool bossdie;
extern bool lastbossdie1;

 //���� ��ǥ
extern int iceX, iceY;
extern int munuhX , munuhY;
extern int slimeX, slimeY;
extern int bossX1, bossY1;
extern int bossX2 , bossY2;
extern int FBX, FBY;
extern int stonX, stonY;
extern int fishX, fishY;

//��Ÿ
extern int OUTEXP;
extern bool OUTEXPTF;
extern bool music;
extern char mapname[256];
extern bool map1;
extern bool map2;
extern int gold;
extern int goldbox;
extern int upgradeN;
extern int upgradeF;
extern int upgradeG;

//test
//extern bool askill;

//���ӿ� ���Ǵ� ��� ��� ���(h)����
#include "Title_Scene.h"
#include "Explain_Scene.h"
#include "Choice_Scene.h"
#include "Nickname.h"
#include "Continue_Scene.h"
#include "Map_Render.h"
#include "Character_Render.h"
#include "Monster_Render.h"
#include "Skill_Render.h"
#include "Menu.h"

#endif
