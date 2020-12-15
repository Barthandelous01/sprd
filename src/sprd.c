#include <config.h>

#ifdef HAVE_UNISTD_H
#  include <unistd.h>
#else
#  error "You need at least a *nix compatability layer to use sprd"
#endif	/* HAVE_UNISTD_H */

#ifndef HAVE_MMAP
#  error "You need at least a *nix compatability layer to use sprd"
#endif	/* HAVE_MMAP */

#ifdef HAVE_SIGNAL_H
#  include <signal.h>
#  include <sys/ioctl.h>
#endif	/* HAVE_SIGNAL_H */

#include <stdlib.h>
#include <getopt.h>
#include <stdio.h>

#include "display.h"
#include "sleep.h"

#define SIGWINCH 31

static struct option longopts[] = {
	{"file", required_argument, NULL, 'f'},
	{"help", no_argument, NULL, 'h'},
	{"wpm", required_argument, NULL, 'w'},
	{"resume", required_argument, NULL, 'r'},
	{"chunks", required_argument, NULL, 'c'},
	{"version", no_argument, NULL, 'V'}
};

/* These are global so that signals can modify them */
int opt = 0, speed = 250, chunks = 1, ind = 1, width = 80;

#ifdef HAVE_SIGNAL_H
void sig_term(int signum)
{
	struct winsize w;
	ioctl(0, TIOCGWINSZ, &w);
	width = w.ws_col;
	reset_line();
}

void exit_int(int signum)
{
	printf("To resume from this point, call with "
		"-r %d\n", ind);
	exit(EXIT_SUCCESS);
}
#endif	/* HAVE_SIGNAL_H */

void usage() {
	printf("Usage: \n\t"PACKAGE_NAME" -f [file] -w [wpm] -c [chunks]\n"
		"\n"
		"OPTIONS:\n"
		"\t-h, --help                 Display this message\n"
		"\t-V, --version              Display version information\n"
		"\t-f, --file                 Select file to read\n"
		"\t-c, --chunks               Select words per chunk\n"
		"\t-w, --wpm                  Select goal words per minute\n"
		"\t-r, --resume               Start at a point midway in\n");
	exit(EXIT_FAILURE);
}

void version()
{
	printf(PACKAGE_STRING"\nCopyright (C) 2020 Barthandelous01\n"
		"License RBSD 3-Clause License.\n"
		"This is free software; you are free to change and redistribute it.\n"
		"There is NO WARRANTY, to the extent permitted by law.\n");
	exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
	/* declare variables */
	char *filename = "a long testing string";

	/* set up signal handlers */
#ifdef HAVE_SIGNAL_H
	signal(SIGINT, &exit_int);
	signal(SIGWINCH, &sig_term);
#endif	/* HAVE_SIGNAL_H */

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
#ifdef HAVE_SIGNAL_H
			ind = atoi(optarg);
			break;
#else
			printf("Resuming from a point is not supported on this platform.");
			break;
#endif
		case 'V':
			version();
			break;
		case ':':
			usage();
			break;
		}
	}

	/* do things */

	return EXIT_SUCCESS;
}
