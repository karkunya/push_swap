#include <stdio.h>
#include <cstdlib>
#include <ctime>

int main()
{
	int i = 50;

	while (i)
	{
		printf("%d ", rand()% 3032);
		i--;
	}
	return 0;
}
