#include "main.h"
/**
 * append_text_to_file - Appends text to the end of an existing file or creates
 *a new file with the specified content.
 *
 * @filename: The name of the file to which the text should be appended
 * @text_content: The content to be appended to the file.
 *
 * Return: 1 on success, -1 on failure.
 *
 * If @filename is NULL, function returns -1.
 *
 * If the file cannot be opened or if write operation fails, the function
 * also returns -1.
 *
 * If  file is successfully opened and content is appended the function
 * returns 1.
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int a, f, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	a = open(filename, O_WRONLY | O_APPEND);
	f = write(a, text_content, len);

	if (a == -1 || f == -1)
		return (-1);

	close(a);

	return (1);
}
