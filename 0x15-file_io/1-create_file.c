#include "main.h"
/**
 * create_file - Creates a new file or overwrites an existing file
 *
 * @filename: The name of the file to be created or overwritten.
 * @text_content: The content to be written to the file.
 *
 * Return: 1 on success, -1 on failure.
 *
 * If @filename is NULL or if the file cannot be created or opened
 * the function returns -1.
 *
 * If @text_content is NULL or if the write operation fail the function
 * returns -1.
 *
 * If the file is created and written the function returns 1.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, f, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	f = write(fd, text_content, len);

	if (fd == -1 || f == -1)
		return (-1);

	close(fd);

	return (1);
}

