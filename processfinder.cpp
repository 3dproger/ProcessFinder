#include "processfinder.h"
#include <windows.h>
#include <tlhelp32.h>

double pf_is_process_running_by_name_a(const char* processName_)
{
    const size_t WCHARBUF = sizeof(processName_) * 2 + 2;
    wchar_t  processName[WCHARBUF];
    MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, processName_, -1, processName, WCHARBUF);

    PROCESSENTRY32W entry;
    entry.dwSize = sizeof(PROCESSENTRY32);

    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

    bool found = false;

    if (Process32First(snapshot, &entry) == TRUE)
    {
        while (Process32Next(snapshot, &entry) == TRUE)
        {
            if (_wcsicmp(entry.szExeFile, processName) == 0)
            {
                found = true;
                break;
            }
        }
    }

    CloseHandle(snapshot);

    return found ? 1.0 : 0.0;
}
