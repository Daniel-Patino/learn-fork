#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	pid_t fid1, fid2, fid3;
	int status;
	
	//fid1 = fork();
	
	fid1 = fork();
	wait(&status);
	
	fid1 = fork();
	wait(&status);

	fid1 = fork();
	wait(&status);
	
	int i = 0;
	
	//for(i = 0; i < 3; i++){
	//	fid1 = fork();
	//	wait(&status);
	//}
	
	if(fid1 == 0){
		//wait(&status);
		printf("This is the Parent\n");
	}
	else{
		printf("Hello Children\n");
	}
	
	return 0;
}