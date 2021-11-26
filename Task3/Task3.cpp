#include <vector>
#include <Windows.h>
#include <Psapi.h>
#include "ProcessDetails.h"

// To ensure correct resolution of symbols, add Psapi.lib to TARGETLIBS
// and compile with -DPSAPI_VERSION=1
ProcessDetails GetProcessDetails(DWORD processID)
{
    TCHAR szProcessName[MAX_PATH] = TEXT("<unknown>");

    // Get a handle to the process.
    HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processID);

    // Get the process name.
    if (NULL != hProcess)
    {
        HMODULE hMod;
        DWORD cbNeeded;

        if (EnumProcessModules(hProcess, &hMod, sizeof(hMod), &cbNeeded))
        {
            GetModuleBaseName(hProcess, hMod, szProcessName, sizeof(szProcessName) / sizeof(TCHAR));
        }
    }

    // Release the handle to the process.
    CloseHandle(hProcess);

    return ProcessDetails(szProcessName, processID);
}

vector<DWORD> GetProcessIds()
{
    DWORD aProcesses[1024], cbNeeded;

    if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
    {
        throw - 1;
    }
   
    vector<DWORD> processIDs;

    for (unsigned int i = 0; i < cbNeeded / sizeof(DWORD); i++)
    {
        if (aProcesses[i] != 0)
        {
            processIDs.push_back(aProcesses[i]);
        }
    }

    return processIDs;
}

vector <ProcessDetails> GetProcessesDetails()
{
    vector<DWORD> processIDs = GetProcessIds();
    vector<ProcessDetails> result;

    for (auto id : processIDs)
    {
        auto myProcess = GetProcessDetails(id);
        result.push_back(myProcess);
    }

    return result;
}
