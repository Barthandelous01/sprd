#include <iostream>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <vector>
#include <csignal>
#include <string>

#include "spritz.hpp"
#include "file.hpp"
#include "chunks.hpp"

int ind = 1;

void exit_int(int signum)
{
     unraw();
     std::cout << std::endl << "To resume from this point, run with -r " << ind << std::endl;
     exit(0);
}

void usage() {
     std::cout << "Usage: sprd -f file [-w WPM] [-c chunks] [-r resume_chunk]";
     exit(-1);
}

int main(int argc, char *argv[])
{
     // set up handler for SIGINT
     signal(SIGINT, &exit_int);
     // set up some variabes
     int speed = 250;
     int chunk = 1;
     std::string filename = "";

     // argument parsing.
     int opt;
     while ((opt = getopt(argc, argv, "f:hw:c:r:")) != -1) {
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
