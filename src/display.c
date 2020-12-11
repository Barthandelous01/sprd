#include <config.h>

#include <stdio.h>

/**
 * center_chunk() - print a string to the center of the terminal
 * @string: the string to print
 * @start: the beginning of the string
 * @end: the end of the string
 * @width: the width of the terminal
 */
void center_chunk(char *string, int start, int end, int width)
{
	printf("%*c%.*s%*c",
		(width - (end - start))/2 - 1, ' ',
		(end-start+1), &string[start],
		(width - (end - start))/2 + 1, ' ');
}
