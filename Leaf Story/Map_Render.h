#ifndef __MAP_RENDER_H__
#define __MAP_RENDER_H__

bool map1to1(float timeDelta);
bool map1to2(float timeDelta);
bool map1to3(float timeDelta);
bool map1toboss(float timeDelta);
bool map2to1(float timeDelta);
bool map2to2(float timeDelta);
bool map2to3(float timeDelta);
bool map2boss(float timeDelta);

void userinfo_Render();
void mapnumber(int x, char name[256]);
void mapnumber2(int x, char name[256]);
void LOG(float timeDelta);
void skill();

extern float regen;
extern float regen2;
extern bool to1;
extern bool to2;
extern bool to3;
extern bool toboss;
extern bool to21;
extern bool to22;
extern bool to23;
extern bool to2boss;

#endif