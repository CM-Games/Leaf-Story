#include "Scene.h"

const int dem = 500000;

bool be_gi(float timdDelta)
{
	charMP -= 1;
	if (to1 == true)
	{
		CharX = iceX + 8;
		iceHP -= dem;
	}
	else if (to2 == true)
	{
		CharX = munuhX;
		munuhHP -= dem;
	}
	else if (to3 == true)
	{
		CharX = slimeX;
		slimeHP -= dem;
	}
	else if (to21 == true)
	{
		CharX = FBX;
		facebookHP -= dem;
	}
	else if (to22 == true)
	{
		CharX = stonX;
		stonX -= dem;
	}
	else if (to23 == true)
	{
		CharX = fishX;
		fishHP -= dem;
	}
	else if (toboss == true)
	{
		CharX = bossX1;
		donutHP -= dem;
	}
	else if (to2boss == true)
	{
		CharX = bossX2;
		doorHP -= dem;
	}

	titlemusic(13, 1);
	return true;
}