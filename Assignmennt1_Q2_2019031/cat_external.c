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

#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>

char *getcwd(char *buf, size_t size);


int main(int argc, char *argv[]){
//        printf("Hullo: aj1 %s aj2 %s \n", argv[0], argv[1]);
        int j = 0; int ctr = 0;
        char newstring[100][100];
//	printf("Entered into file. \n");
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
	char* cwd = calloc(1024, sizeof(char));
//	printf("Huff");
	getcwd(cwd, 1024);//printf("CWD %s", cwd);
	strcat(cwd, "/");
//	printf("CWD: %s", cwd);
	if (newstring[1][0] != '-'){
		strcat(cwd, newstring[1]);
//		printf("Work to be done: %s", cwd);
		FILE* fp;
	      fp = fopen(cwd, "r");
			if (fp == NULL){
				if (errno == 2){
					printf("NO SUCH FILE OR DIRECTORY");
				}
				else if (errno == 21){
				printf("THis is a directory!");
				}
				return 0;
			}
//		int fd = open(cwd, O_WRONLY | O_APPEND);
//		printf("Huppy %s" , cwd);
		char hup[1024];
//		printf("Huppy \n");
//               int kp = write(fd, hup, 1024);
	//       printf("Huggy %s", hup);
	      while (fgets(hup , 1024, fp) != NULL){
	      	printf("%s", hup);
	      }
	      fclose(fp);
	}
	else if (newstring[1][0] == '-'){
		strcat(cwd, newstring[2]);
       //         printf("Work to be done: %s", cwd);
                FILE* fp;
              fp = fopen(cwd, "r");
	  	if (fp == NULL){
                                if (errno == 2){
                                        printf("NO SUCH FILE OR DIRECTORY");
                                }
                                else if (errno == 21){
                                printf("THis is a directory!");
                                }
				return 0;
                        }

//              int fd = open(cwd, O_WRONLY | O_APPEND);
//              printf("Huppy %s" , cwd);
                char hup[1024];
//              printf("Huppy \n");
//               int kp = write(fd, hup, 1024);
        //       printf("Huggy %s", hup);
	if (newstring[1][1] == 'n'){
	int tug = 1;
              while (fgets(hup , 1024, fp) != NULL){
                printf("%d %s", tug, hup);
		tug += 1;
              
	}
	      fclose(fp);
	}
	else if (newstring[1][1] == 'E'){
		while (fgets(hup , 1024, fp) != NULL){
			printf("$");
			for (int yip = 0; hup[yip] != '\n'; yip++){
			printf("%c", hup[yip]);
			}
                printf("$ \n");
              }
              fclose(fp);

	}
	else {
		printf("INVALID OPTION. ");
	}
	}
	      // if (kp < 0){
	 //      	printf("ERROR: %d", errno);
	   //    }
	     //  else{
	//	printf("HO GAYA !! %s", hup);
	  //     }
//	else{
//	printf("Sorry boo");
//	}
	exit(0);

}
