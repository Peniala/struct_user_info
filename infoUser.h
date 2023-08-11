#ifndef USER

#define USER
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct{
		char name[30];
		int uid;
		int gid;
		char direct[50];
		char shell[30];
}User;

User* getInfoUser();
void transferInfo();
#endif
