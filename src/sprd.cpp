#include <iostream>
#include <unistd.h>
#include <chrono>
#include <thread>

#include "chunks.hpp"
#include "file.hpp"

void usage() {
     std::cout << "Usage: sprd -f file [-w WPM] [-c chunks]";
     exit(-1);
}


int main(int argc, char *argv[])
{
     // set up some variabes
     int speed = 250;
     int chunk = 1;
     std::string filename = "";

     // arg parsing switch var
     int opt;
     while ((opt = getopt(argc, argv, "f:hw")) != -1) {
          switch (opt) {
          case 'f' :
               filename = optarg;
               break;
          case 'h':
               usage();
               break;
          case ':':
               std::cout << "That needs an argument.\n";
               usage();
               break;
          }
     }

     std::string file = read_file(filename);
     std::vector<std::string> words = chunks(file);
     centerstring("\\/");
     std::cout << "\n";
     for (std::string x : words) {
          centerstring(x.c_str());
          std::this_thread::sleep_for(std::chrono::milliseconds(500));
     }
}
