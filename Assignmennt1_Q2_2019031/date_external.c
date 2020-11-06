#include<stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
struct tm *gmtime(const time_t *timep);


int main(int argc, char *argv[]){
       // printf("Hullo: aj1 %s aj2 %s \n", argv[0], argv[1]);
        int j = 0; int ctr = 0;
        char newstring[100][100];
        for (int i = 0; i < strlen(argv[1]); i++){
//              printf("HUllo ");
                if (*(argv[1]+ i) == ' ' || argv[1][i] == '\0'){
                        newstring[ctr][j] = '\0';
                        ctr++; j = 0;
                }
                else {
                        newstring[ctr][j] = argv[1][i];
                        j++;
                }
        }
	time_t t;
	 time(&t);
	struct tm*  aj ;
	aj = gmtime(&t);
	if (newstring[1][0] != '-'){
    printf("\n current time is : %s",ctime(&t));
    exit(0);}
	else {
		if (newstring[1][1] == 'u'){
//		printf("%d %d %d %d %d:%d:%d", t.tm_wday, t.tm_mday, t.tm_mon, t.tm_year, t.tm_hour, t.tm_min, t.tm_sec);
		  printf("\n current time (UTC)is : %s",asctime(aj));
    exit(0);		
		}
		else if (newstring[1][1] == 'R'){
/*			char* ans;
			int r = 0;
			char *ut = ctime(&t);
			char* token;
			token = strtok(ut, " ");
			while (token != NULL){
				printf("TOken: %s", token);
			if (r == 0){ 
				char* day = (char*)calloc(1024, sizeof(char));
				 strncpy(token, day, 3);
				strcat(ans, day);
				strcat(ans, ", ");
			}
			else if (r == 2){
				char* day = (char*)calloc(1024, sizeof(char));
					strncpy(token,day, 3);
                                strcat(ans, day);	
			}
			else if(r  == 3 || r == 1){
				strcat(ans, token);
			}
			else if (r == 5){
				printf("TOKEN IS: %s" ,token);
				if (token[8] == 'P'){
					if (token[0] == '0' && token[1] != '9' && token[1] != '8'){
					token[0] = '1';
					}
					if (token[0] == '1'){
						token[0] = 2;
						if (token[1] == '0')token[1] ='2'; 
						if (token[1] == '1')token[1] = '3';
						if (token[1] == '2') token[1] = '4';

					}
					if (token[1] == '8'){
					token[0] = '2'; token[1] = '0';
					}
					if (token[1] == '9' ){
					token[0] = '2'; token[1] = '1';
					}
				}
				strcat(ans, token);
				break;
			}
			token = strtok(NULL, " ");*/
			}
//			printf("Date is %s", ans);
			char jub[1024];
		       	strftime(jub, 1024,"%a %D  %H:%M:%S" ,aj);
			printf("The date is %s", jub);
		}
	}


