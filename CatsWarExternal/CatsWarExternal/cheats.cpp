#include "includes.h"

void AmmoThread()
{
	while (true)
	{
		if (cheats::bAmmo == true)
		{
			WriteProcessMemory(handle::hProc, (LPVOID)( offsets::dwLocalPlayer + offsets::dwMag), &config::dwMagNum, sizeof(float), NULL);
			WriteProcessMemory(handle::hProc, (LPVOID)(offsets::dwLocalPlayer + offsets::dwAmmo), &config::dwAmmoNum, sizeof(float), NULL);
		}
		else
		{
			if (cheats::bAmmoInit == false)
			{
				WriteProcessMemory(handle::hProc, (LPVOID)(offsets::dwLocalPlayer + offsets::dwMag), &init::dwMagInit, sizeof(float), NULL);
				WriteProcessMemory(handle::hProc, (LPVOID)(offsets::dwLocalPlayer + offsets::dwAmmo), &init::dwAmmoInit, sizeof(float), NULL);
				
				cheats::bAmmoInit = true;
			}
		}

		Sleep(1);
	}
}

void HealthThread()
{
	while (true)
	{
		if (cheats::bHealth == true)
		{
			WriteProcessMemory(handle::hProc, (LPVOID)(offsets::dwLocalPlayer + offsets::dwHealth), &config::dwHealthNum, sizeof(float), NULL);
		}
		else
		{
			if (cheats::bHealthInit == false)
			{
				WriteProcessMemory(handle::hProc, (LPVOID)(offsets::dwLocalPlayer + offsets::dwHealth), &init::dwHealthInit, sizeof(float), NULL);
				
				cheats::bHealthInit = true;
			}
		}

		Sleep(1);
	}
}

void FlowerThread()
{
	while (true)
	{
		if (cheats::bFlower == true)
		{
			WriteProcessMemory(handle::hProc, (LPVOID)(offsets::dwLocalPlayer + offsets::dwFlower), &config::dwFlowerNum, sizeof(float), NULL);
		}
		else
		{
			if (cheats::bFlowerInit == false)
			{
				WriteProcessMemory(handle::hProc, (LPVOID)(offsets::dwLocalPlayer + offsets::dwFlower), &init::dwFlowerInit, sizeof(float), NULL);

				cheats::bFlowerInit = true;
			}
		}

		Sleep(1);
	}
}

void AirJumpThread()
{
	while (true)
	{
		if (cheats::bAirJump == true)
		{
			WriteProcessMemory(handle::hProc, (LPVOID)(offsets::dwLocalPlayer + offsets::dwJumpMax), &config::dwJumpMaxNum, sizeof(int), NULL);
			WriteProcessMemory(handle::hProc, (LPVOID)(offsets::dwLocalPlayer + offsets::dwJump), &config::dwJumpNum, sizeof(int), NULL);
		}
		else
		{
			if (cheats::bAirJumpInit == false)
			{
				WriteProcessMemory(handle::hProc, (LPVOID)(offsets::dwLocalPlayer + offsets::dwJumpMax), &init::dwJumpMaxInit, sizeof(int), NULL);
				WriteProcessMemory(handle::hProc, (LPVOID)(offsets::dwLocalPlayer + offsets::dwJump), &init::dwJumpInit, sizeof(float), NULL);

				cheats::bAirJumpInit = true;
			}
		}

		Sleep(1);
	}
}