#include "main.h"

void error_exit(int exit_code, const char *message)
{
	dprintf(STDERR_FILENO, "%s\n", message);
	exit(exit_code);
}


int main(int argc, char *argv[])
{
    const char *file_from;
    const char *file_to;

    int fd_source, fd_dest;
    ssize_t read_bytes, write_bytes;
    char buffer[BUFFER_SIZE];

    if (argc != 3)
    {
	    error_exit(97, "Usage: cp file_from file_to");
    }

    file_from = argv[1];
    file_to = argv[2];

    fd_source = open(file_from, O_RDONLY);
    if (fd_source == -1) {
        error_exit(98, "Error: Can't read from file");
    }

    fd_dest = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
    if (fd_dest == -1) {
        error_exit(99, "Error: Can't write to file");
    }

    while ((read_bytes = read(fd_source, buffer, BUFFER_SIZE)) > 0) {
        write_bytes = write(fd_dest, buffer, read_bytes);
        if (write_bytes == -1) {
            error_exit(99, "Error: Can't write to file");
        }
    }

    if (read_bytes == -1) {
        error_exit(98, "Error: Can't read from file");
    }

    if (close(fd_source) == -1) {
        error_exit(100, "Error: Can't close fd");
    }

    if (close(fd_dest) == -1) {
        error_exit(100, "Error: Can't close fd");
    }

    return 0;
}
