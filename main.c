#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv)
{
	
	// Here we must check our inputs that will determine how many kids we have
	// Between 1 and 7, inclusive. Each one will contain a unique integer between 0 - 9
	
	int pid;
	int amountOfKids = 5;
	int processNum;
	
	// Here we create a loop to create a specified number of children
	for(processNum = 0; processNum < amountOfKids; processNum++){
		// Note No error handling just yet
		pid = fork();
		if(pid == 0){
			break;
		}
	}
	
	// Here we contain the logic for the children and for the parent
	if(pid == 0){
		printf("Hello?\n"); // <= These are all the children
	}
	
	else{
		printf("I'm scared.\n"); // <= This is the single parent
	}
}