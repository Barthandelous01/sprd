#include <iostream>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <vector>
#include <csignal>
#include <string>
#include <getopt.h>
#include <config.h>

#include "spritz.hpp"
#include "file.hpp"
#include "chunks.hpp"
#include "config.hpp"

int ind = 1;

void sig_term(int signum)
{
     std::cout << "\x1b[A" << std::flush;
     centerstring("| ");
     std::cout << std::endl;
}

void exit_int(int signum)
{
     unraw();
     std::cout << std::endl << "To resume from this point, run with -r " << ind << std::endl;
     exit(0);
}

void usage() {
     std::cout << "A blazing-fast (possibly) speedreading program\n"
               << "\n"
               << "USAGE:\n"
               << "    sprd -f file [-w wpm] [-c chunks] [-r resume_point]\n"
               << "\n"
               << "OPTIONS:\n"
               << "-V, --version            Print version info and exit\n"
               << "-h, --help               Print this message and exit\n"
               << "-w, --wpm                Set the words per minute used\n"
               << "-r, --resume             Set the point to resume from\n"
               << "-c, --chunks             Set the number of chunks displayed\n";
     exit(0);
}

void version()
{
     std::cout << PACKAGE_STRING "\nCopyright (C) 2020 Barthandelous01\n\
License RBSD 3-Clause License.\n\
This is free software; you are free to change and redistribute it.\n\
There is NO WARRANTY, to the extent permitted by law.\n";
     exit(0);
}

int main(int argc, char *argv[])
{
     // set up handler for SIGINT
     signal(SIGINT, &exit_int);
     signal(SIGWINCH, &sig_term);

     // set up some variabes
     int speed = 250;
     int chunk = 1;
     std::string filename = STDINPUT;

     // argument parsing.
     int opt;
     static struct option longopts[] = {
          {"file", required_argument, NULL, 'f'},
          {"help", no_argument, NULL, 'h'},
          {"wpm", required_argument, NULL, 'w'},
          {"resume", required_argument, NULL, 'r'},
          {"chunks", required_argument, NULL, 'c'},
          {"version", no_argument, NULL, 'V'}
     };
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
                    chunk = atoi(optarg);
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

     // get file data
     std::string file = read_file(filename);
     std::vector<std::string> words = chunks(file);

     //set raw mode
     raw();

     // do spray
     spray(words, speed, chunk, ind);

     // remove raw
     unraw();
}
