#include<stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include<string.h>
#include<stdlib.h>
#include <errno.h>
#include <unistd.h>

ssize_t write(int fd, const void *buf, size_t count);

int mkdir(const char *pathname, mode_t mode);

int main(int argc, char *argv[]){
//	printf("Hullo: aj1 %s aj2 %s \n", argv[0], argv[1]);
	printf("%ld", strlen(argv[1]));
	int j = 0; int ctr = 0;
	char newstring[100][100];
	printf("Loop STarted");
	for (int i = 0; i < strlen(argv[1]); i++){
  //           printf("HUllo Ayushi ");
                if (*(argv[1]+ i) == ' ' || argv[1][i] == '\0'){
                        newstring[ctr][j] = '\0';
                        ctr++; j = 0;
                }
                else {
                        newstring[ctr][j] = argv[1][i];
                        j++;
                }
        }
//	printf("Kappa %c%c", newstring[1][0], newstring[1][1]);
 //   	printf("THE ARGUMENT SENT TO MKDIR %s", newstring[1]);
       if (newstring[1][0] == '-' && newstring[1][1] == 'v'){
	       if (ctr >= 2){
       		int k = mkdir(newstring[2], 0777);
		if (k < 0){
			write(0,"ERROR IN MAKING FILE KINDLY CHECK", strlen("ERROR IN MAKING FOLDER KINDLY CHECK"));
		if (errno == 2){
			printf("NO SUCH FILE OR DIRECTORY");
		}
		else if (errno == 9){
			printf("NOT A DIRECTORY");
		}
		}
		else{
	       write(0, "MAKING A NEW FOLDER ", strlen("MAKING A NEW FOLDER "));
	       write(0, newstring[2], strlen(newstring[2]));
		}
	       }
       }
       else  if (newstring[1][0] == '-' && newstring[1][1] == 'p'){
	       printf("Kapa ");
	       char *token = strtok(newstring[2], "/");
	       printf("%s", token);
	       char* tmp = (char*) calloc(1024, sizeof(char));
               if (ctr >= 2){   
		       int kj = 0;
		while (token != NULL){   
			if (kj != 0){strcat(tmp, "/");}
			strcat(tmp, token);
			printf("%s", tmp);
                	int k = mkdir(tmp, 0777);
			token = strtok(NULL, "/");
			kj += 1;
			}

              //  if (k < 0){write(0,"ERROR IN MAKING FILE KINDLY CHECK", strlen("ERROR IN MAKING FILE KINDLY CHECK"));}
              //  else{
             //  write(0, "MAKING A NEW FOLDER ", strlen("MAKING A NEW FOLDER "));
              // write(0, newstring[2], strlen(newstring[2]));
        //        }
               }
       
       }
       else{       
	int k = mkdir(newstring[1], 0777);
//        printf("  K: %d \n" , k);
	
              if (k < 0){
                        write(0,"ERROR IN MAKING FILE KINDLY CHECK", strlen("ERROR IN MAKING FOLDER KINDLY CHECK"));
                if (errno == 2){
                        printf("NO SUCH FILE OR DIRECTORY");
                }
                else if (errno == 9){
                        printf("NOT A DIRECTORY");
                }
                }

        
	}
	exit(0);
//        return 0;

}
