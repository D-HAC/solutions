#include <stdlib.h>
#include <stdio.h>

int divide(int x);
int add(int x);
int subtract(int x);

int main(int argc, char *argv[])
{
	int x = atoi(argv[1]);
	
	while(x > 1)
	{
		switch(x%3)
		{
			case 0:
				printf("%d/3\n", x);
				x = x/3;
				break;
			case 1:
				printf("%d - 1\n", x);
				x = x-1;
				break;
			case 2: 
				printf("%d + 1\n", x);
				x = x+1;
				break;
		}
	}
	
	printf("%d\n", x);
	
	return 0;
}