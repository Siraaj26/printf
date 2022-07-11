#include "main.h"

unsigned int convert_c(va_list args, buffer_t *output,
unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_percent(va_list args, buffer_t *output,
unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_p(va_list args, buffer_t *output,
unsigned char flags, int wid, int prec, unsigned char len);

/**
 * convert_c - Converts argument to unsigned char and
 * stores it to buffer contained in a struct.
 * @args: va_list pointing to argument to be converted.
 * @flags: Flag modifiers.
 * @wid: Width modifier.
 * @prec: Precision modifier.
 * @len: Length modifier.
 * @output: buffer_t struct containing a character array.
 * Return: Number of bytes stored to the buffer.
 */

unsigned int convert_c(va_list args, buffer_t *output,
unsigned char flags, int wid, int prec, unsigned char len)
{
char c;
unsigned int ret = 0;
(void)prec;
(void)len;
c = va_arg(args, int);
ret += print_width(output, ret, flags, wid);
ret += _memcpy(output, &c, 1);
ret += print_neg_width(output, ret, flags, wid);
return (ret);
}

/**
 * convert_percent - Stores a percent sign to
 * buffer contained in a struct.
 * @args: va_list pointing to argument to be converted.
 * @flags: Flag modifiers.
 * @wid: width modifier.
 * @prec: Precision modifier.
 * @len: Length modifier.
 * @output: buffer_t struct containing character array.
 * Return: Number of bytes stored to the buffer (always 1).
 */

unsigned int convert_percent(va_list args, buffer_t *output,
unsigned char flags, int wid, int prec, unsigned char len)
{
char percent = '%';
unsigned int ret = 0;
(void)args;
(void)prec;
(void)len;
ret += print_width(output, ret, flags, wid);
ret += _memcpy(output, &percent, 1);
ret += print_neg_width(output, ret, flags, wid);
return (ret);
}
