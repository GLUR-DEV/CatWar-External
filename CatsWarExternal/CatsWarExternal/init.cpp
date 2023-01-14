#include "includes.h"

void InitThread()
{
	ReadProcessMemory(handle::hProc, (LPCVOID)(offsets::dwLocalPlayer + offsets::dwMag), &init::dwMagInit, sizeof(float), NULL);
	ReadProcessMemory(handle::hProc, (LPCVOID)(offsets::dwLocalPlayer + offsets::dwAmmo), &init::dwAmmoInit, sizeof(float), NULL);
	ReadProcessMemory(handle::hProc, (LPCVOID)(offsets::dwLocalPlayer + offsets::dwHealth), &init::dwHealthInit, sizeof(float), NULL);
	ReadProcessMemory(handle::hProc, (LPCVOID)(offsets::dwLocalPlayer + offsets::dwFlower), &init::dwFlowerInit, sizeof(float), NULL);
	ReadProcessMemory(handle::hProc, (LPCVOID)(offsets::dwLocalPlayer + offsets::dwJumpMax), &init::dwJumpMaxInit, sizeof(int), NULL);
	ReadProcessMemory(handle::hProc, (LPCVOID)(offsets::dwLocalPlayer + offsets::dwJump), &init::dwJumpInit, sizeof(int), NULL);
}