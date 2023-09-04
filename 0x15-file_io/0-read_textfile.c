#include "main.h"

/**
 * read_textfile - Read and print text from a file.
 * @filename: The name of the file to read from.
 * @letters: The maximum number of letters to read and print.
 * 
 * Return: The number of letters successfully read and printed. 0 on error.
 */

ssize_t read_textfile(const char *filename, size_t letters) {
    if (filename == NULL)
        return 0;

    FILE *file = fopen(filename, "r");
    if (file == NULL)
        return 0;

    char buffer[BUFSIZE];
    ssize_t total_read = 0;
    ssize_t bytes_read;

    while (letters > 0 && (bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        ssize_t bytes_to_print = bytes_read > letters ? letters : bytes_read;
        ssize_t bytes_written = write(STDOUT_FILENO, buffer, bytes_to_print);

        if (bytes_written < 0 || bytes_written != bytes_to_print) {
            fclose(file);
            return 0;
        }

        letters -= bytes_written;
        total_read += bytes_written;
    }

    fclose(file);
    return total_read;
}
i
