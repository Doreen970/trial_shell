#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	char input[30];
	int status;

	while (1)
	{
		printf("$");
		fflush(stdout);

		if (fgets(input, sizeof(input), stdin) == NULL)
				{
					/*exit if user has no input*/
				break;
				}
				/*get rid of newline character*/
				input[strcspn(input, "\n")] = '\0';
				/*break when user presses exit*/
				if (strcmp(input, "exit") == 0)
					break;
				
				pid_t pid = fork();

				if (pid < 0)
				{
					perror("fork failed");
					exit(1);
				}
				else if (pid == 0)
				{
					execl(input, input, (char *) NULL);
					/*show error if execl fails*/
					perror("execl");
					exit(1);
				}
				else
				{
					wait(&status);
				}
	}
	return (0);
}

					
				
