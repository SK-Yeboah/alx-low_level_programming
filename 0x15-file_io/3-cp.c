#include "main.h"
/**
 * __exit - function that display error messages
 * @error: error status code
 * @str: Pointer to string
 * @fd: file descriptor
 *
 * Return: Always 0 (Success)
 */

int __exit(int error, char *str, int fd)
{
	if (error == 97)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
	} else if (error == 98)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", str);
	} else if (error == 99)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", str);
	} else if (error == 100)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
	} else
	{
		return (0);
	}

	exit(error);
	return (0);
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
	int file_s, file_f;
	int read_stat, write_stat;
	int close_s, close_f;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
	{
		__exit(97, NULL, 0);
	}
	file_s = open(argv[1], O_RDONLY);
	if (file_s == -1)
	{
		__exit(98, argv[1], 0);
	}
	file_f = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY, 0664);
	if (file_f == -1)
	{
		__exit(99, argv[2], 0);
	}
	while ((read_stat = read(file_s, buffer, BUFFER_SIZE)) != 0)
	{
		if (read_stat == -1)
			__exit(98, argv[1], 0);
		write_stat = write(file_f, buffer, read_stat);
		if (write_stat == -1)
		{
			__exit(98, argv[2], 0);
		}
	}
	close_s = close(file_s);
	if (close_s == -1)
	{
		__exit(100, NULL, file_s);
	}
	close_f = close(file_f);
	if (close_f == -1)
	{
		__exit(100, NULL, file_f);
	}
	return (0);
}
