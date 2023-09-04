#include "main.h"

char *allocate_buffer(char *target_file);
void close_descriptor(int descriptor);

/**
 * allocate_buffer - Allocates a buffer of 1024 bytes.
 * @target_file: The name of the target file.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *allocate_buffer(char *target_file)
{
	char *copy_buffer;

	copy_buffer = malloc(sizeof(char) * 1024);

	if (copy_buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Unable to allocate memory for %s\n", target_file);
		exit(99);
	}

	return (copy_buffer);
}

/**
 * close_descriptor - Closes a file descriptor.
 * @fd: The file descriptor to be closed.
 */
void close_descriptor(int fd)
{
	int close_status;

	close_status = close(fd);

	if (close_status == -1)
	{
		dprintf(STDERR_FILENO, "Error: Unable to close file descriptor %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies the content of one file to another file.
 * @argc: The number of command-line arguments.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: Exits with specific error codes in case of incorrect arguments
 * or file-related errors.
 */
int main(int argc, char *argv[])
{
	int source_file, destination_file, read_status, write_status;
	char *copy_buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: copy source_file destination_file\n");
		exit(97);
	}

	copy_buffer = allocate_buffer(argv[2]);
	source_file = open(argv[1], O_RDONLY);
	read_status = read(source_file, copy_buffer, 1024);
	destination_file = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (source_file == -1 || read_status == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Unable to read from source file %s\n", argv[1]);
			free(copy_buffer);
			exit(98);
		}

		write_status = write(destination_file, copy_buffer, read_status);
		if (destination_file == -1 || write_status == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Unable to write to destination file %s\n", argv[2]);
			free(copy_buffer);
			exit(99);
		}

		read_status = read(source_file, copy_buffer, 1024);
		destination_file = open(argv[2], O_WRONLY | O_APPEND);

	} while (read_status > 0);

	free(copy_buffer);
	close_descriptor(source_file);
	close_descriptor(destination_file);

	return (0);
}

