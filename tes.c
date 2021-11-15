#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int		fd;
	char	*res;
	res = (char *)malloc(sizeof(char));
	fd = open("sample3.txt", O_RDONLY);
	if(fd < 0)
		return (0);

	read(fd, res, 1000000000);
	printf("->%s\n", res);
	return (0);
}
