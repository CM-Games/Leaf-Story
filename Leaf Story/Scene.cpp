#include "Scene.h"

//현재 보여지는 장면 번호
int SceneNumber = TITLE_SCENE;

//시스템
char name[256];//닉네임
char readname[256];//닉네임 읽어온거
int CBox;//캐릭터만들기-성별
bool music= true;
char mapname[256];
bool map1 = true;
bool map2 = true;

int upgradeN = 0; //Now업글수치
int upgradeF = 1; //미래업글수치
int upgradeG = 1000; //업글비용

//캐릭터
int gold = 5000; //소지골드
int goldbox = 0; //얻은골드
int sex;//성별
int CharX = 6, CharY = 19;//캐릭 좌표
int charEXP = 0; //최초 경험치
int charLV = 1; //최초 레벨
int expbar = 100; //최초 필요 경험치
int charHP = 100; //최초 체력
int charMP = 100; //최초 마력
int OUTEXP;
bool monDeath = false;//사망 구분
bool OUTEXPTF = false;//경험치로그
bool nomal_attack;// 어택 모션
int max_attack=25;//최초 최대 공격력
int mini_attack=10;//최초 최소 공격력
bool chardie = false;//캐릭터 사망 구분
int max_charHP = 50;//레벨업시 최대 체력 증가
bool charLR = false; //캐릭 왼쪽 오른쪽 구분
int potion = 2;

//몬스터 체력 및 관련
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

//몬스터 좌표
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
//장면선택 렌더링 함수
bool SceneRender(float timeDelta)
{
	//장면 번호에 따라 Render 호출 변경
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
