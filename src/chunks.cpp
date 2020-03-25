#ifndef CHUNKS_CPP_
#define CHUNKS_CPP_

#include <vector>
#include <sstream>
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

#endif /* CHUNKS_CPP_ */
