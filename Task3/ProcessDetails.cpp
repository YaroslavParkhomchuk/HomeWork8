#include <iostream>
#include "ProcessDetails.h"
using namespace std;

wostream& operator<< (wostream& out, const ProcessDetails& processDetails)
{
	out << processDetails.id << " " << processDetails.name;
	return out;
}

DWORD ProcessDetails::getID() const
{
	return id;
}
