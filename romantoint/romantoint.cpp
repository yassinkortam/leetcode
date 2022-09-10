#include <iostream>
#include <string>

class Solution {
public:
    int romanToInt(std::string s) {
      int integer = 0;
      char roman;
      char next;
      for (int i=0; i < s.length(); i++){
        roman = s[i];
        next = 'I';
        if (i < s.length() - 1)  next = s[i+1];
        switch(roman){
          case 'I':
            if (next == 'V' || next == 'X') integer -= 1;
            else integer += 1;
            break;
          case 'V':
            integer += 5;
            break;
          case 'X':
            if (next == 'L' || next == 'C') integer -= 10;
            else integer += 10;
            break;
          case 'L':
            integer += 50;
            break;
          case 'C':
            if (next == 'D' || next == 'M') integer -= 100;
            else integer += 100;
            break;
          case 'D':
            integer += 500;
            break;
          case 'M':
            integer += 1000;
            break;
        }
      }
      return integer;
    }
};

int main() {
  Solution solution;
  std::cout << solution.romanToInt("MMXXII");
}
