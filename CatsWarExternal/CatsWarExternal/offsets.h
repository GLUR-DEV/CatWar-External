#pragma once

#include "includes.h"

namespace handle
{
	extern const char* gameName = "CatsWar-Win64-Shipping.exe";
	extern DWORD procId = 0;
	extern HANDLE hProc = 0;
}

namespace offsets
{
	extern uintptr_t dwModule{};
	extern uintptr_t dwPlayerOffset = 0x48F6CC8;
	extern uintptr_t dwLocalPlayer{};

	extern uintptr_t dwBase1{};
	extern uintptr_t dwBase2{};
	extern uintptr_t dwBase3{};
	extern uintptr_t dwBase4{};
	extern uintptr_t dwBase5{};

	extern uintptr_t dwMag = 0x534;
	extern uintptr_t dwAmmo = 0x59C;
	extern uintptr_t dwHealth = 0x550;
	extern uintptr_t dwFlower = 0x530;
	extern uintptr_t dwJumpMax = 0x2C0;
	extern uintptr_t dwJump = 0x348;
}
