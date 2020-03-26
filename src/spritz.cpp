#ifndef SPRITZ_CPP_
#define SPRITZ_CPP_

#include <vector>
#include <string>
#include <chrono>
#include <thread>

#include "wpm.hpp"
#include "chunks.hpp"


using std::vector;
using std::string;

void spray(vector<string> words, int wpm, int chunks, int resume)
{
     // set up variables
     std::chrono::milliseconds delay = time_per_word(wpm, chunks);
     centerstring("| ");
     std::cout << std::endl;
     string temp = "";
     int index = 1;

     for (string x : words) {
          if (index < resume) {
               index++;
               continue;
          }
          temp += x + " ";
          if (index % chunks == 0) {
               centerstring(temp.c_str());
               std::cout << std::flush;
               temp = "";
               std::this_thread::sleep_for(delay);
          }
          index++;
     }
}


#endif /* SPRITZ_CPP_ */
