#pragma once
#include <windows.h>
#include <string>
using namespace std;

class ProcessDetails
{
public:
    ProcessDetails(wstring _name, DWORD _id) : name(_name), id(_id) {}
    friend wostream& operator<< (wostream&, const ProcessDetails&);
    DWORD getID() const;

private: 
    wstring name;
    DWORD id;
};
