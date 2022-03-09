#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {

public:
    bool isIsomorphic(std::string s, std::string t) {
      if (s.length() != t.length()) return false;
      std::unordered_map<char, char> charmap;
      int len =  s.length(), count = 0;
      for (int i = 0; i < len; i++)
      {
        char schar = s.at(i), tchar = t.at(i);
        if ((charmap.count(schar) & !charmap.count(tchar)) || (!charmap.count(schar) & charmap.count(tchar)))
        {
          return false;
        }
        if (!charmap.count(schar) & !charmap.count(tchar))
        {
          charmap[schar] = count;
          charmap[tchar] = count;
        } else
        {
          if (charmap[schar] != charmap[tchar])
          {
            return false;
          }
        }
      }
      return true;
    }
};