#include </usr/include/stdio.h>
#include </usr/include/stdlib.h>
#include </usr/include/lib.h>

int getprocnr( int pidValue);

int main( int argc, char *argv[])
{
    int pid, i, index;

    if( argc !=2 )
    {
	printf("Wrong no. of args");
	return 1;
    }
    else 
    {
	index = atoi(argv[1]);
	for( i = 0; i < 10; i++)
	{
		pid = getprocnr(index+i);
		if( pid != -1)
			printf("Process with index %d was found. PID: %d\n", index, pid);
		else
			printf("Process with index %d was not found", index);
	}
    }
return 0;
}
