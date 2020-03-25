#ifndef FILE_CPP_
#define FILE_CPP_

#include <string>
#include <fstream>

using std::string;

string read_file(string path)
{
     std::ifstream t;
     t.open(path);
     string buffer, line;
     while(t) {
          std::getline(t, line);
          buffer.append(line);
          buffer.append(" ");
     }
     return buffer;
}

#endif /* FILE_CPP_ */
