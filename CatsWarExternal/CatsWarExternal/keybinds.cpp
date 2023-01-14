#include "includes.h"

int delay = 300;

void KeybindThread()
{
	while (true)
	{
		if (GetAsyncKeyState(VK_LCONTROL) & GetAsyncKeyState(0x31))
		{
			if (cheats::bAmmo == false)
			{
				std::cout << "[ctr + 1] Pressed. Unlimited Ammo on.\n";
				InitThread();

				cheats::bAmmoInit = false;
			}
			else
			{
				std::cout << "[ctr + 1] Pressed. Unlimited Ammo off.\n";
			}

			cheats::bAmmo = !cheats::bAmmo;
			Sleep(delay);
		}

		if (GetAsyncKeyState(VK_LCONTROL) & GetAsyncKeyState(0x32))
		{
			if (cheats::bHealth == false)
			{
				std::cout << "[ctr + 2] Pressed. Unlimited Health on.\n";
				InitThread();

				cheats::bHealthInit = false;
			}
			else
			{
				std::cout << "[ctr + 2] Pressed. Unlimited Health off.\n";
			}

			cheats::bHealth = !cheats::bHealth;
			Sleep(delay);
		}

		if (GetAsyncKeyState(VK_LCONTROL) & GetAsyncKeyState(0x33))
		{
			if (cheats::bFlower == false)
			{
				std::cout << "[ctr + 3] Pressed. Instant Win on.\n";
				InitThread();

				cheats::bFlowerInit = false;
			}
			else
			{
				std::cout << "[ctr + 3] Pressed. Instant Win off.\n";
			}

			cheats::bFlower = !cheats::bFlower;
			Sleep(delay);
		}

		if (GetAsyncKeyState(VK_LCONTROL) & GetAsyncKeyState(0x34))
		{
			if (cheats::bAirJump == false)
			{
				std::cout << "[ctr + 4] Pressed. AirJump on.\n";
				InitThread();

				cheats::bAirJumpInit = false;
			}
			else
			{
				std::cout << "[ctr + 4] Pressed. AirJump off.\n";
			}

			cheats::bAirJump = !cheats::bAirJump;
			Sleep(delay);
		}

		Sleep(1);
	}
}