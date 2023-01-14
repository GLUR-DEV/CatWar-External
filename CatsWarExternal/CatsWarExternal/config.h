#pragma once

#include "includes.h"

namespace init
{
	float dwMagInit;
	float dwAmmoInit;
	float dwHealthInit;
	float dwFlowerInit;
	int dwJumpMaxInit;
	int dwJumpInit;
}

namespace cheats
{
	bool bAmmo = false;
	bool bAmmoInit = false;

	bool bHealth = false;
	bool bHealthInit = false;

	bool bFlower = false;
	bool bFlowerInit = false;

	bool bAirJump = false;
	bool bAirJumpInit = false;
}

namespace config
{
	float dwMagNum = 6969;
	float dwAmmoNum = 6969;

	float dwHealthNum = 6969;
	
	float dwFlowerNum = 10;

	float dwJumpMaxNum = 6969;
	float dwJumpNum = -1;
}
