#include "main.h"
/**
 * read_textfile - reads a text file and prints it to the standard output
 * @filename: name of the file to be read
 * @letters: number of letters to read and print
 * Return: the number of letters printed, or 0 if it failed
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int file_descriptor;
	int r_result, w_result;
	char *buffer;

	if (!filename)
	{
		return (0);
	}

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor < 0)
	{
		return (0);
	}

	buffer = malloc(sizeof(char) * letters);
	if (!buffer)
	{
		close(file_descriptor);
		return (0);
	}

	r_result = read(file_descriptor, buffer, letters);
	if (r_result < 0)
	{
		free(buffer);
		close(file_descriptor);
		return (0);
	}

	buffer[r_result] = '\0';
	close(file_descriptor);
	w_result = write(STDOUT_FILENO, buffer, r_result);

	free(buffer);

	if (w_result < 0)
		return (0);

	return (w_result);
}
