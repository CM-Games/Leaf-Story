#ifndef __SCENE_H__
#define __SCENE_H__
using namespace std;
//Draw / Input 헤더(h) Include
#include "Draw.h"
#include "Input.h"
#include "FileIO.h"
#include "RemoveBar.h"
#include <Windows.h>
#include <ctime>

//노래
#include <conio.h>
#include <iostream>
#include "fmod.hpp"
#pragma	comment (lib, "fmodex_vc.lib")
using namespace FMOD;

//장면선택 렌더링 함수
bool SceneRender(float timeDelta);

enum Scene
{
	TITLE_SCENE,EXPLAIN_SCENE,CHOICE_SCENE,NICKNAME,CONTINUE_SCENE,MAP_ONE,MAP_TWO,MAP_THREE,MAP_BOSS,MENU_SCENE,UPGRADE,SHOP,MAP_TWO_ONE, MAP_TWO_TWO, MAP_TWO_THREE,MAP_TWO_BOSS
	
};//타이틀,설명,캐릭터선택,닉네임짓기,이어하기
//현재 보여지는 장면번호
//extern을 사용해서 Scene.cpp의 변수를 공유
extern int SceneNumber;
extern int CBox;
extern char name[256];
extern int sex;
extern char readname[256];

//캐릭터
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

//몬스터 
extern int munuhHP;
extern int slimeHP;
extern int iceHP;
extern int donutHP;
extern int facebookHP;
extern int stonHP;
extern int fishHP;
extern int doorHP;
extern bool monDeath;//몬스터 죽음 체크
extern bool monHIT;
extern bool bossdie;
extern bool lastbossdie1;

 //몬스터 좌표
extern int iceX, iceY;
extern int munuhX , munuhY;
extern int slimeX, slimeY;
extern int bossX1, bossY1;
extern int bossX2 , bossY2;
extern int FBX, FBY;
extern int stonX, stonY;
extern int fishX, fishY;

//기타
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

//게임에 사용되는 모든 장면 헤더(h)파일
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
