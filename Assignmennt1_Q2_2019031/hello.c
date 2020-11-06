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

int chdir(const char *path);
int fchdir(int fd);
int cd(char *pth);
int pwd();
//int echo(char* str[100], int k);
int execv(const char *file, char *const argv[]);
int cd(char* pth);
int pwd(char str[100][100]);
int echo(char str[100][100] , int k);
int history(char HISTORY[100][100], int no_of_c, char str[100][100], char* pth);
int mkdir_externl(char str[100][100], char* input);
int cat_external(char* input);
int rm_external(char str[100][100], char* input);
int date_external(char* input);
int ls_external(char* input);
#include <sys/types.h> 
#include <sys/wait.h> 

pid_t wait(int *status); 
pid_t waitpid(pid_t pid, int *status, int options); 




char CURR_PATH[1024];

int main(){
	getcwd(CURR_PATH, sizeof(CURR_PATH));
	int no_of_commands = 0;
	printf("Welcome! \n");
	int flag = 1;
	char HISTORY[100][100];
	FILE* fp;
//	fp = fopen("history.txt", "w");
	 int fd = open("history.txt", O_WRONLY | O_APPEND);
	// fp = fopen("history.txt", "r");

	while (flag != 0){

		char newstring[100][100];
//		char **newstring = (char**)malloc(1024 *sizeof(char* ));
		
	printf("> ");
	char* str = (char *) calloc(1024, sizeof(char));
	read(0, str, 1024);
	if (str[0] != 'h'){
	int g = write(fd, str, strlen(str));
//	printf("DID THE COMMEND WRITE: %d", g);
	if (g < 0){
		printf("PERROR:1  %d \n", errno);
	}
	}
	int h_l = 0; int h_l_sub = 0;
	for (int i = 0; str[i] != '\0'; i++){
	HISTORY[no_of_commands][h_l_sub] = str[i];
	h_l_sub += 1;
	}
	no_of_commands += 1;
	printf("%s %ld ", str, strlen(str));
	int j = 0; int ctr = 0;
	for (int i = 0; i < strlen(str); i++){
//		printf("HUllo ");
		if (*(str+ i) == ' ' || str[i] == '\0'){
			newstring[ctr][j] = '\0';
			ctr++; j = 0;
		}
		else {
			newstring[ctr][j] = str[i];
			j++;
		}
	}
//	for (int i = 0; i <= ctr; i++){
//	printf("%s\n", newstring[i]);}
//	printf("%s", str);
	if (strcmp(newstring[0], "pwd")== 0){
//		printf("%s \n", getenv("PWD"));
		pwd(newstring);
//		write(0, getenv("PWD"), strlen(getenv("PWD")));
	}
	else if (strcmp(newstring[0], "cd") == 0){
//		printf("PRINTING VALUE OF CD[1] \n");
		write(0, newstring[1], 100);
		cd(newstring[1]);
	//	if (strcmp(newstring[1], "/")){
			
	//		write(0, "using chdir \n", strlen("using chdir"));
	//		int k = chdir(newstring[1]);
	//		printf("K == %d \n", k);
	//		if (k == -1){write(0, "could not change the directory \n", strlen("could not change the diretcory \n"));}			cd(newstring[2]);
	//		write(0, getenv("PWD"), strlen(getenv("PWD")));
	//		write(0, "\n", strlen("\n"));

	//	}
	//	else{

	//		write(0, "not recognised :-(", strlen("not recognised :-("));
		//}
	}
	else if (strcmp(newstring[0], "exit") == 0){
		write(0, "EXIT.. ", strlen("EXIT.. "));
		return 0;
	}
	else if (strcmp(newstring[0], "cat") == 0){
		cat_external(str);
	}
	else if (strcmp(newstring[0], "echo") == 0){
		echo(newstring, ctr);
	}
	else if (strcmp(newstring[0], "history") == 0){
		history(HISTORY, no_of_commands, newstring, str);
	/*	char *ptr = (char *)calloc(1024, sizeof(char));
		int k = 0;
		int kp = open("history.txt", O_RDONLY);
		int j = read(kp , ptr , 1024);
		if (j < 0){
			printf("ERROR IN READING THE FILE: %d", errno);
		}
		printf("%s", ptr);
		free(ptr);*/
	} 
	else if (strcmp(newstring[0], "mkdir") == 0){
		mkdir_externl(newstring, str);
	}
	else if (strcmp(newstring[0], "rm") == 0){
		printf("HUllo RM me");
		rm_external(newstring, str);
	}
	else if (strcmp(newstring[0], "date") == 0){
		date_external(str);
	}
	else if (strcmp(newstring[0], "ls") == 0){
		ls_external(str);
	}
	else {
		printf("INVALID COMMAND");
	}
//	flag  = 0;
	}
}
int cd(char* pth){
	char cwd[1024];
//	printf("Character at pth %c", *pth);
	if (pth[0] == '-' && pth[1] == '-' && pth[2] == 'h' && pth[3] == 'e' && pth[4] == 'l' && pth[5] == 'p'){
		printf("Used to change directories. ");

		return 0;
	}
	if (*pth != '/'){
	getcwd(cwd, sizeof(cwd));
	strcat(cwd, "/");
//	printf("%s", cwd );
	if (strcmp(pth, "..") == 0){
		int jubba = chdir(pth);
		if (jubba < 0){
			printf("ERROR IN CHANGING THE DIRECTORY");
			return 0;
		}
		int nup = strlen(CURR_PATH);
//		printf("NUP: %d", nup);
		while (nup != -1){ 
		if( CURR_PATH[nup]== '/'){
		break;
		}
		nup -=1 ;
		}
		CURR_PATH[nup] = '\0';
//		printf("JUmping Backs");
		return 0;
	}
	strcat(cwd, pth);
//	printf("CWD Being printed: %s", cwd);
	int tubby = chdir(cwd);
//	printf("TUBBY: %d", tubby);
	if (tubby >= 0){
		strcat(CURR_PATH, "/");
		strcat(CURR_PATH, pth);
		printf("Current Working Directory: %s", cwd);
	}
	else{
	if (errno == 2)	printf("NO SUCH FILE OR DIRECTORY \n");
	else if (errno == 20) printf("NOT A DIRECTORY \n");
	else {
	printf("ERROR");
	}
	}
//	printf("PWD RN:  %s \n", getenv("PWD"));
	return 0;
	}
	else{
		int s = chdir(pth);
		if (s < 0){
			printf("%s", strerror(errno));
		}
	//	printf("TUBBYS: %d", s);
	}
}
int pwd(char str[100][100]){
	char cwd[1024];
	char* tuba = getcwd(cwd, 1024);
	if (tuba == NULL){
	printf("%s", strerror(errno));
	return 0;
	}
	printf("PWD IS %s \n", cwd);
	if (str[1][0] == '-' && str[1][1] == 'P'){
//	write(0, getenv("PWD"), strlen(getenv("PWD")));
	write(0 ,cwd, strlen(cwd)); 
	printf("\n");
	}
	else if (str[1][0] == '-' && str[1][1] != 'L'){
		printf("INVALID OPTION ENTERED");
	}
	else{
	write(0, CURR_PATH, strlen(CURR_PATH));}
	printf("\n");
	return 0;
}

int echo(char str[100][100] , int k){
//	printf("Hi friends! ");
	if (str[1][0] != '*' && str[1][0]  != '-')
	{//	for (int i  =1; i < k; i++){
	//printf("%s",  str[i]);
	for (int i  = 1; i < k; i++){
       // printf("%s",  str[i]);
        strcat(str[i], " ");
        int t = write(0, str[i], strlen(str[i]));
	if (t < 0){
		printf("ERROR IN WRITING THE ARGUMENS: %s", strerror(errno));
	}
              //  write(0, "\n", strlen(" \n"));
strcat(str[i], " ");
	//write(0, str[i], strlen(str[i]));}
	//	write(0, "\n", strlen(" \n"));
	}
	write(0, "\n", strlen("\n"));
	}
	else if (str[1][0] == '*'){
	struct dirent *de;
	DIR *dr = opendir(".");
	if (dr == NULL){
		printf("ERROR IN OPENING THE DIRECTORY. ");
	}
	while ((de = readdir(dr)) != NULL){
		printf("%s \n", de->d_name);
	}
	closedir(dr);
	}
	else if (str[1][0] == '-' && str[1][1] == 'E'){
	for (int i  =2; i < k; i++){
        //printf("%s",  str[i]);
        strcat(str[i], " ");
        write(0, str[i], strlen(str[i]));}
                write(0, "\n", strlen(" \n"));

	}
	//closedir(dr);

else if (str[1][0] == '-' && str[1][1] == 'n'){
		for (int i  = 2; i <k; i++ ){
		strcat(str[i], " ");
        write(0, str[i], strlen(str[i]));}

	return 0;
}
else if (str[1][0] == '-'){
	printf("INVALID OPTION ENTERED. ");
}
}
int history(char HISTORY[100][100], int no_of_c, char str[100][100], char* pth){
	int st = -1;
	printf("%s ", str[1]);
	if (str[1][0] == '-' && str[1][1] == 'c'){
		printf("HISTORY DELETING.. \n");
		FILE* fp;
		fp = fopen("history.txt", "w");
	}
	else if (str[1][0] == '!' && str[1][1] == '!'){
		FILE *kf = fopen("history.txt", "r");
		char dublub[1024];int yu = 0;
		while (fgets(dublub, 1024, kf) != NULL){
	//		printf("DUBLUBDUBLUB: %s", dublub);
			yu += 1;
		}
		int st = 0;
		FILE *kg = fopen("history.txt", "r");
		while (fgets(dublub, 1024, kg)){
		if (st == yu){
	//		printf("DUBLUB %s", dublub);
		}
		st += 1;
		}
		printf("Your previous command: %s \n", dublub);
	}
	else if (no_of_c >= 2){
		printf("INVALID OPTION ");
	}
	else{
		FILE *kf = fopen("history.txt", "r");
                char dublub[1024];int yu = 0;
                while (fgets(dublub, 1024, kf) != NULL){
                      printf(" %s ", dublub);
                      //  yu += 1;
                }

	char *ptr = (char *)calloc(10000, sizeof(char));

                int k = 0;
              //  int kp = open("history.txt", O_RDONLY);
              //  int j = read(kp , ptr , 10000);
               // if (j < 0){
                //        printf("ERROR IN READING THE FILE: %d", errno);
               // }
               // printf("Hullo %s \n", ptr);//                free(ptr);//		printf("Did it");
}
//	printf("1");
	int fd = open("history.txt", O_WRONLY);
//	printf("2");

	int g = write(fd, pth , 1024);
//	printf("3");
      // printf("DID THE COMMEND WRITE: %d", g);
        if (g < 0){
                printf("PERROR: 3 %d \n", errno);
        }

	return 0;
}
int mkdir_externl(char str[100][100], char* input){
	int status;
	printf("ENtered here . ");
	int jk = fork();
//	printf("JK: %d", jk);
	if (jk == 0){
		printf("CHILD PROECSS ");
	char* argv[3];
	argv[1] = input;
	argv[2] = NULL;
	printf("%s", getenv("PWD"));
//	printf("ARGS: 0 %s1 %s 2 %s \n", *argv, *(argv + 1), *(argv + 2));
//	char path[1024]; // printf("Ooooooooo");
//	*path = getenv("PWD"); 
//	char *tubby = calloc(1024, sizeof(char));
//	*tubby = getenv("PWD");
//	getcwd(path, 1024);
//	printf("Kya baat hai :-): %s", path);
//	strcat(path, "/mkdir_external");
//	*path = "/mkdir_external" ;
//	argv[0] = path;
	char* path = calloc(1024, sizeof(char));
                path = getenv("PWD");
                strcat(path, "/mkdir_external");

//	 printf("ARGS: 0 %s1 %s 2 %s \n", *argv, *(argv + 1), *(argv + 2));
//	 printf("TUbby : %s", *tubby);
//	argv[0] = "/home/ayushi3127/Desktop/OS_Course_Assignments/Assignment1.1/Assignment_1.1_2/mkdir_external";
	argv[0] = path;
		int s = execv(*argv , argv);	printf("IS S: %d ", s);
	printf("HUllo %s", path);
	if (s < 0){
                printf("errno: %d", errno);

 }

	exit(0);
	}
	else{
	int st = waitpid(-1, &status, 0);
//	printf("PARENT PROECSS WORKED! %d %d", jk, st);}
/*	int k = mkdir(str[1], 0777);
	printf("K: %d \n" , k);
	if (k < 0){
		printf("errno: %d", errno);
	}*/
	return 0;
	
}
}
int cat_external(char* input){
	int status;
	int pid = fork();
//	printf("PID; %d", pid);
	if (pid == 0){
		char* argv[3];
		char* path = calloc(1024, sizeof(char));
		path = getenv("PWD");
		strcat(path, "/cat_external");
		argv[0] = path;
		argv[1] = input;
		argv[2] = NULL;
		int s = execv(*argv, argv);
//		printf("IS S: %d", s);
		exit(0);
	}
	else{
		waitpid(-1, &status,0);
//		printf("PARENT PROCESS");
		return 0;
	}
}
int rm_external(char str[100][100], char* input){
	int status;
	int pid = fork();
//	printf("PID: %d", pid);
	if (pid == 0){
		char* argv[3];
		char* path = calloc(1024, sizeof(char));
                path = getenv("PWD");
                strcat(path, "/rm_external");
		argv[0] = path;
		argv[1] = input;
		argv[2] = NULL;
		int s = execvp(*argv, argv);
//		printf("IS S: %d", s);
		exit(0);
	}
	else{
		waitpid(-1, &status,0 );
//		printf("PARENT PROECSS");
		return 0;

	}
//	printf("STR[1]: %s", str[1] );
//	int k = rmdir(str[1]);
//	printf("K: %d", k);
	return 0;
}
int date_external(char* input){
	int status; int pid = fork();
//	printf("PID: %d", pid);
	if (pid == 0){
		char* argv[3];
		 char* path = calloc(1024, sizeof(char));
                path = getenv("PWD");
                strcat(path, "/date_external");
                argv[0] = path;
                argv[1] = input;
                argv[2] = NULL;
               int s = execvp(*argv, argv);
  //              printf("IS S: %d", s);
                exit(0);
        }
        else{
                waitpid(-1, &status,0 );
              //  printf("PARENT PROECSS");
                return 0;

        }

//	time_t t;
  //  time(&t);
//    printf("\n current time is : %s",ctime(&t));
//	gettimeofday(&current_time, NULL);
//	printf("seconds: %ld ", current_time.tv_sec);

}

int ls_external(char* input){
	int status; int pid = fork();
	if (pid == 0){
		char* argv[3];
		char* path = calloc(1024, sizeof(char));
                path = getenv("PWD");
                strcat(path, "/ls_external");
		argv[0] = path;
		argv[1] = input;
		argv[2] = NULL;
		int s = execvp(*argv, argv);
//		printf("S: %d", s);
		exit(0);
	}
	else {
	waitpid(-1, &status,0 );
                printf("PARENT PROECSS");
                return 0;

	}
}

