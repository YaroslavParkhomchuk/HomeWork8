#include <fstream>
#include <vector>
#include <Windows.h>
#include <algorithm>
#include "Task3.h"
#include "Main.h"
using namespace std;

int main(void)
{
    vector<ProcessDetails> result;

    try 
    {
        result = GetProcessesDetails();
    }
    catch (...)
    {
        return -1;
    }

    sort(result.begin(), result.end(), [](ProcessDetails a, ProcessDetails b) -> bool { return a.getID() > b.getID(); });

    wofstream file;
    file.open("D:\\out.txt");

    for (auto i : result)
    {
       file << i << endl;
    }

    file.close();
    return 0;
}


