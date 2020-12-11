#include <config.h>

#ifdef HAVE_UNISTD_H
#  include <unistd.h>
#else
#  error "You need at least a *nix compatability layer to use sprd"
#endif	/* HAVE_UNISTD_H */

#ifndef HAVE_MMAP
#  error "You need at least a *nix compatability layer to use sprd"
#endif	/* HAVE_MMAP */

#include <stdlib.h>
#include <signal.h>
#include <getopt.h>
#include <stdio.h>

#define SIGWINCH 31

void sleep_ms(int ms);

static struct option longopts[] = {
	{"file", required_argument, NULL, 'f'},
	{"help", no_argument, NULL, 'h'},
	{"wpm", required_argument, NULL, 'w'},
	{"resume", required_argument, NULL, 'r'},
	{"chunks", required_argument, NULL, 'c'},
	{"version", no_argument, NULL, 'V'}
};

void sig_term(int signum)
{
	if(signum){}
}

void exit_int(int signum)
{
	if(signum){}
}

void usage() {
	exit(EXIT_FAILURE);
}

void version()
{
	exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
	/* declare variables */
	char *filename;
	int opt, speed = 250, chunks = 1, ind = 1;

	/* set up signal handlers */
	signal(SIGINT, &exit_int);
	signal(SIGWINCH, &sig_term);

	/* suppress warnings; for now */
	if(opt){}
	if(speed){}
	if(ind){}
	if(filename){}
	if(chunks){}
	
	/* argument parsing */

	while ((opt = getopt_long(argc, argv, "f:hw:c:r:V", longopts, NULL)) != -1) {
		switch (opt) {
		case 'f' :
			filename = optarg;
			break;
		case 'h':
			usage();
			break;
		case 'w':
			speed = atoi(optarg);
			break;
		case 'c':
			chunks = atoi(optarg);
			break;
		case 'r':
			ind = atoi(optarg);
			break;
		case 'V':
			version();
			break;
		case ':':
			usage();
			break;
		}
	}

	/* do things */
	printf("%s\n", "Do default thing");

	return EXIT_SUCCESS;
}
