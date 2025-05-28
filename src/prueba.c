

#include <stdio.h>
#include <string.h>
int	main(int argc, char **argv, char **envp) {
	int i = -1;
	while (envp[++i])
	{
		printf("%s\n", envp[i]);
	}
}
