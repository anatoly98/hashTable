#define _CRT_SECURE_NO_WARNINGS 

#include "md5.h"
#include "map.h"


void MAP::add(char *unit)
{
	DWORD md5[4];
	MD5(unit, sizeof(unit) - 1, md5);
	strcpy(data[md5[3] % 256], unit);

}

void MAP::del(char *unit)
{
	DWORD md5[4];
	MD5(unit, sizeof(unit) - 1, md5);
	strcpy(data[md5[3] % 256], "unknown unit");
}
bool MAP::contain(char *unit)
{
	DWORD md5[4];
	MD5(unit, sizeof(unit) - 1, md5);
	if (!(strcmp(data[md5[3] % 256], "unknown unit")))
		return false;
	else return true;
}
