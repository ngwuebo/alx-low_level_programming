#include "main.h"
#include <stdlib.h>

/* read and print a text file to stdout */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t fd, bytes_read, bytes_written;
	char *buffer;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	bytes_read = read(fd, buffer, letters);
	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);

	if (fd == -1 || bytes_read == -1 || bytes_written == -1 || bytes_written != bytes_read)
	{
		free(buffer);
		return (0);
	}

	free(buffer);
	close(fd);

	return (bytes_written);
}
