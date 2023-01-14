#include "includes.h"

uintptr_t GetModuleBaseAddress(DWORD procId, const char* modName)
{
    uintptr_t modBaseAddr = 0;
    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, procId);
    if (hSnap != INVALID_HANDLE_VALUE)
    {
        MODULEENTRY32 modEntry;
        modEntry.dwSize = sizeof(modEntry);
        if (Module32First(hSnap, &modEntry))
        {
            do
            {
                if (!_stricmp(modEntry.szModule, modName))
                {
                    modBaseAddr = (uintptr_t)modEntry.modBaseAddr;
                    break;
                }
            } while (Module32Next(hSnap, &modEntry));
        }
    }
    CloseHandle(hSnap);
    return modBaseAddr;
}

void FindProcId()
{
    PROCESSENTRY32 entry;
    entry.dwSize = sizeof(PROCESSENTRY32);

    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

    if (Process32First(snapshot, &entry) == TRUE)
    {
        while (Process32Next(snapshot, &entry) == TRUE)
        {
            if (_stricmp(entry.szExeFile, handle::gameName) == 0)
            {
                handle::procId = entry.th32ProcessID;
            }
        }
    }

    CloseHandle(snapshot);
}

void GetModule()
{
    while (true)
    {
        offsets::dwModule = GetModuleBaseAddress(handle::procId, handle::gameName);

        offsets::dwBase1 = offsets::dwModule + offsets::dwPlayerOffset;
        ReadProcessMemory(handle::hProc, (LPCVOID)offsets::dwBase1, &offsets::dwBase2, sizeof(uintptr_t), NULL);

        offsets::dwBase3 = offsets::dwBase2 + 0x0;
        ReadProcessMemory(handle::hProc, (LPCVOID)offsets::dwBase3, &offsets::dwBase4, sizeof(uintptr_t), NULL);

        offsets::dwBase5 = offsets::dwBase4 + 0x20;
       ReadProcessMemory(handle::hProc, (LPCVOID)offsets::dwBase5, &offsets::dwLocalPlayer, sizeof(uintptr_t), NULL);

        Sleep(100);
    }
}

void Login()
{
    
}

int main()
{
    FindProcId();
    if (handle::procId == NULL)
    {
        std::cout << "Failed to get target process pid. Are you sure Cats War is running?\n";
        std::cout << "GetLastError: " << GetLastError() << std::endl;
        return EXIT_FAILURE;
    }

    handle::hProc = OpenProcess(PROCESS_ALL_ACCESS, false, handle::procId);
    if (handle::hProc == NULL)
    {
        std::cout << "Failed to open target process. Are you sure Cats War is running?\n";
        std::cout << "GetLastError: " << GetLastError() << std::endl;
        return EXIT_FAILURE;
    }

    std::thread mod(GetModule);

    Sleep(1000);

    std::thread thread1(InitThread);
    std::thread thread2(KeybindThread);

    std::thread thread4(AmmoThread);
    std::thread thread5(HealthThread);
    std::thread thread6(FlowerThread);
    std::thread thread7(AirJumpThread);

    Login();

    std::cout << "Cheat made by GLUR. GLUR#4861 on discord\n";
    std::cout << "If you downloaded this program from anywhere other than the my github(https://github.com/GLUR-DEV) then your computer may be at risk. If this is the case delete all traces of this program now!\n\n";

    std::cout << "Keybinds:\n";
    std::cout << "[ctr + 1] For Unlimited Ammo\n";
    std::cout << "[ctr + 2] For Unlimited Health\n";
    std::cout << "[ctr + 3] For Instant Win(You have to pick up a flower for it to register)\n";
    std::cout << "[ctr + 4] For Airjump\n\n";

    std::cout << "Log:\n";

    Sleep(10000000000000);
}