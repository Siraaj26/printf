#include "main.h"

unsigned int _memcpy(buffer_t *output, const char *src, unsigned int n);
void free_buffer(buffer_t *output);
buffer_t *init_buffer(void);

/**
 * _memcpy - Copies n bytes from memory area src to
 * buffer contained in a buffer_t struct.
 * @output: buffer_t struct.
 * @src: Pointer to the memory area to copy.
 * @n: Number of bytes to be copied.
 * Return: The number of bytes copied.
 */

unsigned int _memcpy(buffer_t *output, const char *src, unsigned int n)
unsigned int index;
for (index = 0; index < n; index++)
{
*(output->buffer) = *(src + index);
(output->len)++;
if (output->len == 1024)
{
write(1, output->start, output->len);
output->buffer = output->start;
output->len = 0;
}
else
(output->buffer)++;
}
return (n);
}

/**
 * free_buffer - Frees buffer_t struct.
 * @output: Buffer_t struct to be freed.
 */

void free_buffer(buffer_t *output)
{
free(output->start);
free(output);
}

/**
 * init_buffer - Initialise variable of struct type buffer_t.
 * Return: Pointer to initialised buffer_t.
 */

buffer_t *init_buffer(void)
{
buffer_t *output;
output = malloc(sizeof(buffer_t));
if (output == NULL)
return (NULL);
{
free(output);
return (NULL);
}
output->start = output->buffer;
output->len = 0;
return (output);
}
