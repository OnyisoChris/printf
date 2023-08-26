#include "main.h"

/**
 * handle_flags - Finds and calculates active flags
 * @format: Character String
 * @p: a pointer to an integer
 * Return: Flags
 */
int handle_flags(const char *format, int *p)
{
	int x, crnt_index;
	int format_flags = 0;
	const char FLAGS_CH[] = {'+', ' ', '#', '0', '-', '\0'};
	const int FLAGS_ARR[] = {FLAG_PLUS, FLAG_SPACE, FLAG_HASH,
		FLAG_ZERO, FLAG_MINUS, 0};

	crnt_index = *p + 1;
	while (format[crnt_index] != '\0')
	{
		for (x = 0; FLAGS_CH[x] != '\0'; x++)
		{
			if (format[crnt_index] == FLAGS_CH[x])
			{
				format_flags |= FLAGS_ARR[x];
				break;
			}
		}
		if (FLAGS_CH[x] == 0)
			break;
		crnt_index++;
	}
	*p = crnt_index - 1;

return (format_flags);
}
