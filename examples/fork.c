#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define NUM_CHILD 5

int main() {

	int pid;
	int i;

	i = 0;
	printf("Este es el pid del proceso padre: %i \n", getpid());
	while (i < NUM_CHILD)
	{
		pid = fork();
		if (pid) {
		printf("Este es el pid del proceso padre: PID:%i | getpid= %i \n", pid, getpid());
		}
		else
		{
			printf("Este es el pid del proceso hijo: PID:%i | getpid= %i \n", pid, getpid());
			exit(0);
		}
		i++;	
	}	

	while (1)
	{
		printf("PID: %i\tGETPID: %i\n", pid, getpid());
		sleep(5);
	}
	return (0);
}
