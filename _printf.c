Skip to content
Search or jump to…
Pull requests
Issues
Marketplace
Explore
 
@YOHANNES-cmd 
Adebayo-S
/
printf
Public
Code
Issues
Pull requests
Discussions
Actions
Projects
1
Wiki
Security
Insights
printf/_printf.c
@Adebayo-S
Adebayo-S [fix]: case E and r appended
Latest commit 02af940 on Apr 21
 History
 2 contributors
@Adebayo-S@Gejix
51 lines (48 sloc)  1.17 KB

#include "main.h"

/**
 * _printf - formatted output conversion and print data.
 * @format: input string.
 *
 * Return: number of chars printed.
 */

int _printf(const char *format, ...)
{
	int i = 0, j = 0, buff_count = 0, prev_buff_count = 0;
	char buffer[2000];
	va_list arg;
	call_t container[] = {
		{'c', parse_char}, {'s', parse_str}, {'i', parse_int}, {'d', parse_int},
		{'%', parse_perc}, {'b', parse_bin}, {'o', parse_oct}, {'x', parse_hex},
		{'X', parse_X}, {'u', parse_uint}, {'R', parse_R13}, {'r', parse_rev},
		{'\0', NULL}
	};

	if (!format)
		return (-1);
	va_start(arg, format);
	while (format && format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++, prev_buff_count = buff_count;
			for (j = 0; container[j].t != '\0'; j++)
			{
				if (format[i] == '\0')
					break;
				if (format[i] == container[j].t)
				{
					buff_count = container[j].f(buffer, arg, buff_count);
					break;
				}
			}
			if (buff_count == prev_buff_count && format[i])
				i--, buffer[buff_count] = format[i], buff_count++;
		}
		else
			buffer[buff_count] = format[i], buff_count++;
		i++;
	}
	va_end(arg);
	buffer[buff_count] = '\0';
	print_buff(buffer, buff_count);
	return (buff_count);
}
Footer
© 2022 GitHub, Inc.
Footer navigation
Terms
Privacy
Security
Status
Docs
Contact GitHub
Pricing
API
Training
Blog
About
You have no unread notifications
