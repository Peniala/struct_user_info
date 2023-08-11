#include "infoUser.h"
User* getInfoUser(){
	User* users = malloc(60*sizeof(User));

	FILE* file=fopen("/etc/passwd","r");
	if(file==NULL){
		exit(1);
	}
	
	char ligne[250];
	char x[20];
	int i=0;
	while(fgets(ligne,250,file)!=NULL){
		sscanf(ligne,"%[^:]:%[^:]:%d:%d:%*[^:]:%[^:]:%s\n",users[i].name,x,&users[i].uid,&users[i].gid,users[i].direct,users[i].shell);
		//printf("%s,%d,%d,%s,%s\n",users[i].name,users[i].uid,users[i].gid,users[i].direct,users[i].shell);
		i++;
	}
	fclose(file);
	return users;
}
void transferInfo(){
	User* users = malloc(60*sizeof(User));
	users = getInfoUser();

	FILE* f=fopen("infoUser.csv","w");
	if(f==NULL){
		exit(1);
	}
	
	fprintf(f,"User,Mail,Mot de passe,UID,GID,Répertoire perso,Shell\n");
	int passwrd;
	char mail[50];
	srand(time(NULL));
	
	for(int j=0; j<60; j++){
		passwrd = 1 + (int)(100.0*rand()/(RAND_MAX + 100.0));
		if(users[j].uid >= 1000 && users[j].uid <= 1100){
			sprintf(mail,"%s@mit.mg",users[j].name);
			fprintf(f,"%s,%s,%d,%d,%d,%s,%s\n",users[j].name,mail,passwrd,users[j].uid,users[j].gid,users[j].direct,users[j].shell);
		}
	}
	fclose(f);
}
