#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
void delay(int number_of_seconds) 
{ 
    int milli_seconds = 1000 * number_of_seconds; 
  
    clock_t start_time = clock(); 
  
    while (clock() < start_time + milli_seconds) ; 
}
void main()
{
	int pid = fork();
	if (pid > 0){
		printf("hello parent %d %d\n",pid,getpid());
		delay(30000);
		printf(" parent awake %d %d\n",pid,getpid());
		exit(0);
}
	else
	{
	printf("hi child exit%d %d \n",pid,getpid());
	// delay (1000);
	printf("child in zombie process %d %d \n",pid,getpid());
	exit(0);	
	}
}
