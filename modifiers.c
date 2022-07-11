#include "main.h"

unsigned int print_width(buffer_t *output, unsigned int printed,
unsigned char flags, int wid);
unsigned int print_string_width(buffer_t *output,
unsigned char flags, int wid, int prec, int size);
unsigned int print_neg_width(buffer_t *output, unsigned int printed,
unsigned char flags, int wid);

/**
 * print_width - Stores leading spaces to buffer for width modifier.
 * @output: buffer_t struct containing character array.
 * @printed: Current number of characters already printed to output
 * for a given number specifier.
 * @flags: Flag modifiers.
 * @wid: Width modifier.
 * Return: Number of bytes stored to the buffer.
 */

unsigned int print_width(buffer_t *output, unsigned int printed,
unsigned char flags, int wid)
{
unsigned int ret = 0;
char width = ' ';
if (NEG_FLAG == 0)
{
for (wid -= printed; wid > 0;)
ret += _memcpy(output, &width, 1);
}
return (ret);
}

/**
 * print_string_width - Stores leading spaces to buffer for width modifier.
 * @output: buffer_t struct containing a character array.
 * @flags: Flag modifiers.
 * @wid: Width modifier.
 * @prec: Precision modifier.
 * @size: Size of the string.
 * Return: The number of bytes stored to the buffer.
 */

unsigned int print_string_width(buffer_t *output,
unsigned char flags, int wid, int prec, int size)
{
unsigned int ret = 0;
char width = ' ';
if (NEG_FLAG == 0)
{
wid -= (prec == -1) ? size : prec;
for (; wid > 0; wid--)
ret += _memcpy(output, &width, 1);
}
return (ret);
}

/**
 * print_neg_width - Stores trailing spaces to buffer for a '-' flag.
 * @output: buffer_t struct containing a character array.
 * @printed: Current number of bytes already stored to output
 * for a given specifier.
 * @flags: Flag modifiers.
 * @wid: Width modifier.
 * Return: Number of bytes stored to the buffer.
 */

unsigned int print_neg_width(buffer_t *output, unsigned int printed,
unsigned char flags, int wid)
{
unsigned int ret = 0;
char width = ' ';
if (NEG_FLAG == 1)
{
for (wid -= printed; wid > 0; wid--)
ret += _memcpy(output, &width, 1);
}
return (ret);
}
