#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int isValidInput(int argc, char** argv);

int main(int argc, char** argv)
{
	
	/* Initialization */
	pid_t child_pid;
	int status;
	
	int amountOfKids = argc - 1; // We subtract one because the first element shouldn't count
	int processNum;
	
	// Here we must check our inputs that will determine how many kids we have
	// Between 1 and 7, inclusive. Each one will contain a unique integer between 0 - 9
	if(child_pid != 0){
		isValidInput(argc, argv);
		printf("!!!!!!!TEST!!!!!!!");
	}

	// Here we create a loop to create a specified number of children
	int childSpecificNumber = 0;
	
	for(processNum = 0; processNum < amountOfKids; processNum++){
		child_pid = fork();
		if(child_pid >= 0){
			if(child_pid == 0) /* fork() returns 0 for child process */
				break;
		}
		else{ /* failure */
			perror("fork");
			exit(0);
		}
		childSpecificNumber++;
	}
	
	// Here we contain the logic for the children and for the parent
	if(child_pid == 0){
		printf("Child: %d\n", childSpecificNumber); // <= These are all the children
	}
	
	else{
		wait(&status);
		wait(&status);
		wait(&status);
		printf("Parent Process: %d", childSpecificNumber); // <= This is the single parent
	}
}

/** This function ensures that the input parameters are valid, the input parameters
	must meet the following criteria in order for this function to return a true;
	first there must a number of arguments between 1 - 7, where the first item does
	not count in this number. Next each of these arguments must be unique integers
	0 - 9.
	
	@params		int argc	The number of parameters coming into our process
				char* argv	An array containing each of the individual numbers
	@return		TRUE or FALSE
*/

int isValidInput(int argc, char** argv)
{
	
	//printf("We are Inside: argc: %d", argc);
	//argv = malloc(sizeof(char[argc]));
	
	int i = 0;
	for(i = 1; i < argc; i++){
		printf("%s ",argv[i]);
	}
	
	printf("\n");
	return 1;
}
