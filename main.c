#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

#include "fibonacci.h"

void check_fork(pid_t PID)
{
	if (PID < 0) 
	{ 
		printf("\nThere was an error creating a child process to execute the Fibonacci sequence. Try again later.\n");
		exit(1);
	}
}

int main()
{
	pid_t PID;

	printf("\n.:: Starting main process... <PID#%d>\n", getpid());
	printf(".:: Create child process.. \n");

	PID = fork();
	check_fork(PID);

	if (PID == 0) {
		printf("\n    .:: Starting child process.. <PID#%d>\n", getpid());
		fibonacci(); 
		printf("    .:: Child process closed! <PID#%d>\n", getpid());
		exit(0);
	}

	printf(".:: Waiting for child process to finish.. \n");
	wait(NULL);
	printf("\n.:: Returning to the main process.. \n");
	printf(".:: Main process closed! <PID#%d> \n\n", getpid());

	return 0;
}

