#include <config.h>

#include <stdio.h>
#include <unistd.h>

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
	fflush(stdout);
}

/**
 * reset_line() - go back to the beginning of a line
 *
 * Make sure that the cursor is at the begining of the current
 * line.
 */
void reset_line()
{
	printf("\r");
	fflush(stdout); 	/* make sure there's nothing extra left */
}
