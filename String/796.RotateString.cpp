#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
      int rotation = 0;
      int len = s.length();
      while (rotation < len+1)
      {
        string t = s.substr(rotation, len) + s.substr(0, rotation);
        if (t == goal) return true;
        rotation++;
      }
      return false;
    }
};

