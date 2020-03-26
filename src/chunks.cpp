#ifndef CHUNKS_CPP_
#define CHUNKS_CPP_

#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>
#include <vector>
#include <sstream>
#include <cstring>
#include <string>

using std::string;
using std::vector;

vector<string> chunks(string file)
{
     string tmp;
     std::stringstream string_stream(file);
     vector<string> chunks;
     while(string_stream >> tmp) {
          chunks.push_back(tmp);
     }
     return chunks;
}

void centerstring(const char *s)
{
     // get terminal size
     struct winsize w;
     ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
     //print padding to center
     int l = strlen(s);
     int pos=(int)((w.ws_col-l)/2);
     for(int i = 0; i < pos; i++)
          std::cout << " ";
     std::cout << s << "     \r" << std::flush;
}

#endif /* CHUNKS_CPP_ */
