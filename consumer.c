
#include <stdio.h>
int main()
{
	int i;
	
	for(i=0;i<20;i++)
	{
		scanf("%d",&i);
		if (i%2==0)
		{
			printf("%d",i);
		}
	}

	printf("\n");

	return 0;
}
