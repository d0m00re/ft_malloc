#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	char *addr;

	i = 0;
	while (i < 1024)
		addr = (char *)malloc(1024);
		i++;
	return (0);
}
