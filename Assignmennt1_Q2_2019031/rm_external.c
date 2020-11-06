#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>
#include <stdlib.h>
#include <unistd.h>
 #include <errno.h>

int rmdir(const char *pathname);
int remove(const char *pathname);



int main(int argc, char *argv[]){
//	printf("AYUSHI IS DA BEST : - ) ");
  //      printf("Hullo: aj1 %s aj2 %s \n", argv[0], argv[1]);
   	// printf("STR[1]: %s", str[1] );
	int j = 0; int ctr = 0;
	 char newstring[100][100];
        for (int i = 0; i < strlen(argv[1]); i++){
                if (*(argv[1] + i) == ' ' || argv[1][i] == '\0'){
                        newstring[ctr][j] = '\0';
                        ctr++; j = 0;
                }
                else {
                        newstring[ctr][j] = argv[1][i];
                        j++;
                }
        }
	char path_[1024];
       getcwd(path_, 1024);
       printf("PATH: %s", path_);
       strcat(path_, "/");
       printf("%s %s ", path_, newstring[1]);
       if (newstring[1][0] == '-' && newstring[1][1] == 'f'){
	if (ctr >= 2)	{strcat(path_, newstring[2]);
//	printf("PATH FINAL %s ", path_ );
//	printf("ARGUMENT IN THE REAL FUNCTION: %s", newstring[2]);}
      int k = remove(path_);
 
      }
}
       else if (newstring[1][0] == '-' && newstring[1][1] == 'i'){
       	if (ctr >= 2){
		strcat(path_, newstring[2]);
		write(0, "Are you sure you want to delete the file? ", 100  );
		printf("Okayy lets see");
		char* t = calloc(1024, sizeof(char));
		read(0, t, 1);
		printf("T: %s", t);
		if (strcmp(t, "Y") == 0 || strcmp(t, "y") == 0){
			printf("OKAY \n");
		//	int k = rmdir(path_);
			int k = remove(path_);
			if (k < 0){
				if (errno == 21){
				printf("THIS IS A DIRECTORY");						}
				else if (errno == 2){
					printf("NO SUCH FILE EXISTS");
				}
			}
		}
	}
       }
       else{
       	strcat(path_, newstring[1]);
	int k  = remove(path_);
	if (k < 0){
		printf("ERROR IN removing file: %d", errno);

                                if (errno == 21){
                                printf("THIS IS A DIRECTORY");                                          }
                                else if (errno == 2){
                                        printf("NO SUCH FILE EXISTS");
                                }
                        }


       }
return 0;
}
  //    printf("K: %d", k);
//	int k = mkdir(argv[1], 0777);
    //    printf("  K: %d \n" , k);
//      exit();
   


     
