#include<stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include<string.h>
#include<stdlib.h>
 #include <errno.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include<errno.h>

char *getcwd(char *buf, size_t size);


int main(int argc, char *argv[]){
        printf("Hullo: aj1 %s aj2 %s \n", argv[0], argv[1]);
        int j = 0; int ctr = 0;
        char newstring[100][100];
        printf("Entered into file. \n");
        for (int i = 0; i < strlen(argv[1]); i++){
//              printf("HUllo ");
                if (argv[1][i] == ' ' || argv[1][i] == '\0'){
                        newstring[ctr][j] = '\0';
                        ctr++; j = 0;
                }
                else {
                        newstring[ctr][j] = argv[1][i];
                        j++;
                }
	}
        struct dirent *de;
	char* pth;
	getcwd(pth, 1024);
        DIR *dr = opendir(".");
	if (dr == NULL){
		printf("ERROR : %s", strerror(errno));
	}
	if (newstring[1][0] == '-' && newstring[1][1] == 'Q'){
		if (ctr >= 2){
			char *pth = (char *) calloc(1024, sizeof(char));
		       	getcwd(pth, 10000);
			printf("path %s newstring %s",pth,  newstring[2]);
			strcat(pth, "/");
			strcat(pth, newstring[2]);
			dr = opendir(pth);}
        while ((de = readdir(dr)) != NULL){
		char* red = de->d_name;
		if (*red != '.'){
                printf("\"%s\"", de->d_name);}
		printf("\n");
		
	}
        closedir(dr);
	}
	else if (newstring[1][0] == '-' && newstring[1][1] == '1'){
		if (ctr >= 2){
		 char *pth = (char *) calloc(1024, sizeof(char));
                        getcwd(pth, 10000);
                        printf("path %s newstring %s",pth,  newstring[2]);
                        strcat(pth, "/");
                        strcat(pth, newstring[2]);
                        dr = opendir(pth)	;
			
		//	dr = opendir(newstring[2]);
			}
		while ((de = readdir(dr)) != NULL){
                printf("%s \n", de->d_name);
        }
        closedir(dr);

	}
	else if (newstring[1][0] == '-'){
		printf("INVALID OPTION");
	}
	else {
		if (ctr >= 2){
			 char *pth = (char *) calloc(1024, sizeof(char));
                        getcwd(pth, 10000);
                        printf("path %s newstring %s",pth,  newstring[2]);
                        strcat(pth, "/");
                        strcat(pth, newstring[2]);
                        dr = opendir(pth);	
			
//			dr = opendir(newstring[2]);
		}
		 while ((de = readdir(dr)) != NULL){
                printf("%s ", de->d_name);
	}
		 closedir(dr);
	}
	return 0;
}
