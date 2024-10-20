#include "monty.h"

/**
 * my_getline - Read a line from a file stream
 * @lineptr: Pointer to the buffer storing the line
 * @n: Pointer to the size of the buffer
 * @stream: File stream to read from
 *
 * Return: The number of characters read, or -1 on failure or end of file
 *
 * Description: Reads a line from the specified file stream and stores it in
 * the buffer pointed to by lineptr.
 * The buffer is dynamically resized as needed.
 */
int my_getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t bufsize = 0;
	int c;
	int len = 0;
	char *new_lineptr;

	if (!lineptr || !n || !stream)
		return (-1);

	while ((c = fgetc(stream)) != EOF)
	{
		if (len >= (int)(*n) - 1)
		{
			bufsize += 128;
			new_lineptr = realloc(*lineptr, bufsize);
			if (!new_lineptr)
				return (-1);
			*lineptr = new_lineptr;
			*n = bufsize;
		}

		(*lineptr)[len++] = (char)c;

		if (c == '\n')
			break;
	}

	if (len == 0)
		return (-1);

	(*lineptr)[len] = '\0';

	return (len);
}

/**
 * my_strdup - Duplicate a string
 * @str: The string to duplicate
 *
 * Return: A pointer to the newly allocated duplicate string
 *
 * Description: Allocates memory for a new string and copies the contents
 * of the specified string into it.
 */
char *my_strdup(const char *str)
{
	size_t len = strlen(str) + 1;
	char *new_str = malloc(len);

	if (new_str != NULL)
	{
		memcpy(new_str, str, len);
	}

	return (new_str);
}

