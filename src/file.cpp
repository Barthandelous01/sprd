#ifndef FILE_CPP_
#define FILE_CPP_

#include <string>
#include <fstream>
#include <iostream>

#include "config.hpp"

using std::string;

string read_file(string path)
{
     string buffer = "";
     if (path != STDINPUT){
          std::ifstream t;
          t.open(path);
          string line;
          while(t) {
               std::getline(t, line);
               buffer.append(line);
               buffer.append(" ");
          }
     } else {
          string line;
          while(std::cin) {
               std::getline(std::cin, line);
               buffer.append(line);
               buffer.append(" ");
          }
     }
     return buffer;
}

#endif /* FILE_CPP_ */
