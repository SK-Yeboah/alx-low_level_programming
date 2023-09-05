#include "main.h"

/**
 * read_textfile-Read and print text from a file.
 * @filename: The name of the file to read from.
 * @letters: The maximum number of letters to read and print.
 *
 * Return: The number of letters successfully read and printed. 0 on error.
 */

ssize_t custom_read_textfile(const char *file_name, size_t num_letters)
{
	int file_descriptor;
	int read_result, write_result;
	char *buffer;

	if (!file_name)
	{
		return (0);
	}

	file_descriptor = open(file_name, O_RDONLY);
	if (file_descriptor < 0)
	{
		return (0);
	}

	buffer = malloc(sizeof(char) * num_letters);

	if (!buffer)
	{
		close(file_descriptor);
		return (0);
	}

	read_result = read(file_descriptor, buffer, num_letters);

	if (read_result < 0)
	{
		free(buffer);
		close(file_descriptor);
		return (0);
	}

	buffer[read_result] = '\0';
	close(file_descriptor);

	write_result = write(STDOUT_FILENO, buffer, read_result);

	free(buffer);

	if (write_result < 0)
	{
		return (0);
	}
	return (write_result);
}
