#include<stdio.h>
#include <stdlib.h>                                                                            
#include <unistd.h>                                                                          
#include <signal.h> 

int main()
{
	pid_t temp=getpid();
	printf("%d\n",temp);
	kill(temp,SIGKILL);
	printf("Hello\n");
	printf("Hello\n");
	printf("Hello\n");
	return 0;
}
