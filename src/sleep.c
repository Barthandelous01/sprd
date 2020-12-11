#include <config.h>

#if _POSIX_C_SOURCE >= 199309L
#  include <time.h>
#else
#  include <unistd.h>
#endif

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
