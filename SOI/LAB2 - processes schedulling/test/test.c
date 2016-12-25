#include <stdio.h>
#include <stdlib.h>
#include <lib.h>
#include <sys/types.h>
#include <unistd.h>

/* Some test function. Written by Lolsiak ( Walczakp007) */

int main(int atgc, char *argv[])
{	

message m;
int i, j, priority, procPid;
if( argc != 2)
{
	printf("Wrong no. of arguments");
	return 1;
}

procPid = getpid();
priority = atoi(argv[1]);
m.m1_i1 = procPid;
m.m2_i2 = priority;
_syscall(MM,SETPRI,&m);
printf("Start of Test. PID: %d, PRIORITY: %d \n", procPid, priority);

for (i = 0; i < 99999; i++)
	for( j = 0; j < 10000; j++);
   		/* work work work work work.... */

printf("End of Test. PID %d, Priority: %d \n", procPid, priority);

}


