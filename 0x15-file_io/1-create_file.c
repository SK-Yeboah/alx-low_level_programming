#include "main.h"

/**
 * create_file - creates a file and fills it with text
 * @filename: name of the file to create
 * @text_content: text to write in the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int file_d;
	int b_written;
	int y = 0;

	if (!filename)
		return (-1);

	file_d = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	if (file_d < 0)
		return (-1);

	if (text_content)
	{
		while (text_content[y])
			y++;
		b_written = write(file_d, text_content, y);
		if (b_written != y)
			return (-1);
	}

	close(file_d);

	return (1);
}
