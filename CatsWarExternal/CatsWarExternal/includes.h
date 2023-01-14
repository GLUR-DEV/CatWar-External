#pragma once

#include <Windows.h>
#include <iostream>
#include <TlHelp32.h>
#include <thread>
#include <fstream>
#include "tchar.h"

#include "offsets.h"
#include "config.h"

void InitThread();
void KeybindThread();
void GetModule();
void Login();

void AmmoThread();
void HealthThread();
void FlowerThread();
void AirJumpThread();
