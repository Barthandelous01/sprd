#include <config.h>

#if _POSIX_C_SOURCE >= 199309L
#  include <time.h>
#else
#  include <unistd.h>
#endif

#include <ctype.h>

/**
 * sleep_ms() - sleep for the specified number of miliseconds
 * @ms: the number of miliseconds to sleep for
 *
 * Sleep in as cross-platform a way as *nix supports. Credit
 * to
 * https://stackoverflow.com/questions/1157209/
 * is-there-an-alternative-sleep-function-in-c-to-milliseconds
 * for the POSIX version.
 */
void sleep_ms(int ms)
{
#if _POSIX_C_SOURCE >= 199309L
	struct timespec ts;
	ts.tv_sec = ms / 1000;
	ts.tv_nsec = (ms % 1000) * 1000000;
	nanosleep(&ts, NULL);
#else
	if (ms >= 1000)
		sleep(ms / 1000);
	usleep((ms % 1000) * 1000);
#endif
}

/**
 * time_incriment() - get the amount we should be sleeping
 * @wpm: the goal WPM
 * @chunks: the number of chunks being used
 *
 * time_incriment() returns the number of miliseconds to
 * sleep to correctly based on WPM and number of chunks used.
 */
int time_incriment(int wpm, int chunks)
{
	return 60000/(wpm/chunks);
}

/**
 * next_chunk() - find the next chunk of a string
 * @string: the string to chunk
 * @start: the current start point
 * @end: set to the end of the chunk
 * @chunks: the number of words to get
 * @length: the length of the string
 *
 * next_chunk() takes a start point and gets the start and
 * end points of the next chunk section of a string. Does not
 * modify, clone, or do any string comparisons on @string. If
 * set, @end will be overwritten. Use a length parameter
 * rather than null-termintation because this is intended to
 * be used with an mmap-ed file.
 */
void next_chunk(char *string, int start, int *end, int chunks, int length)
{
	int i = 0, j = 0;
	if (isspace(string[start]) || string[start] == '\n')
		j++;

	while (i < chunks) {
		if (isspace(string[start+j]) || string[start+j] == '\n') {
			i++;
			j++;
			continue;
		} else if (start + j == length) {
			break;
		} else {
			j++;
		}
	}
	*end = start + j - 1;
}
