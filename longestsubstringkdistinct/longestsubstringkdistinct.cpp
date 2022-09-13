using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class LongestSubstringKDistinct {
 public:
  static int findLength(const string& str, int k) {
    int maxLength = 0, currentLength = 0;
    int numUniqueChars = 0;
    int windowStart = 0, windowEnd = 0;
    char currentChar;
    // TODO: Write your code here
    unordered_map <char,int> uniqueChars;
  
    while (windowEnd < str.length()){
      //Expanding the map normally
      while (numUniqueChars <= k){
        currentChar = str[windowEnd];
        if (uniqueChars.find(currentChar) == uniqueChars.end()){
          uniqueChars[currentChar] = 0;
        } 
        else uniqueChars[currentChar]++;
        numUniqueChars = uniqueChars.size();
        windowEnd++;
        currentLength++;
      }

      //When we reach our constraint
      while (numUniqueChars > k){
        currentChar = str[windowStart];
        if (uniqueChars.find(currentChar) != uniqueChars.end()){
          if (uniqueChars[currentChar] == 0) uniqueChars.erase(currentChar);
          else uniqueChars[currentChar]--;
        }
        numUniqueChars = uniqueChars.size();
        windowStart++;
        currentLength--; 
      
        maxLength = max(maxLength, currentLength);
      }
    }
    return maxLength;
  }
};
