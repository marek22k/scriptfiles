// The author of this program is Marek Küthe
// Website: mk16.de
// E-Mail: m.k@mk16.de

#include <stdio.h>

int main()
{
	printf("Hello User! Enter a number:\n");
	int num;
	scanf("%d", &num);
	
	if(num < 0)
	{
		printf("The number is crazy!\n");
	}
	else if(num%2 == 0)
	{
		printf("The number is good!\n");
	}
	else
	{
		printf("The number is bad!\n");
	}
	
	return 0;
}