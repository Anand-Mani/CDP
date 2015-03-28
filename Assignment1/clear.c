#include<stdio.h>
//#define ANSI_ESCAPE_SEQUENCE(EscapeSeq)   "\33[" EscapeSeq

main()
{
		//write(1, "\33[H\33[2J", 7);
		printf("\33[H\33[2J");
}
