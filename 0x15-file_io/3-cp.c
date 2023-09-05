#include "main.h"


void error_exit(int exit_code, const char *message)
{
	dprintf(STDERR_FILENO, "%s\n", message);
	exit(exit_code);
}
/**
 * main - copies the content of a file to another file
 * @argc: number of arguments passed to the program
 * @argv: array of arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	int fd_r, fd_w, x, m, n;
	char buf[BUFSIZ];

	if (argc != 3)
	{
		error_exit(97,  "Usage: cp file_from file_to\n");
	}

	fd_r = open(argv[1], O_RDONLY);
	if (fd_r < 0)
	{
		error_exit(98,  "Usage: cp file_from file_to\n");
	}

	fd_w = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	while ((x = read(fd_r, buf, BUFSIZ)) > 0)
	{
		if (fd_w < 0 || write(fd_w, buf, x) != x)
		{
			error_exit(99,  "Usage: cp file_from file_to\n");
			close(fd_r);
		}
	}

	if (x < 0)
	{
		error_exit(98,  "Usage: cp file_from file_to\n");
	}

	m = close(fd_r);
	n = close(fd_w);
	if (m < 0 || n < 0)
	{
		if (m < 0)
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_r);
		if (n < 0)
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_w);
		exit(100);
	}
	return (0);
}
