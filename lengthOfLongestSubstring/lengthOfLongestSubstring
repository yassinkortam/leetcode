#include <unordered_map>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map <char, int> characters; //store characters in umap
        
        int currentLength = 0, maxLength = 0; //initialize length values
        
        char currentChar, pastChar; 
        int windowStart = 0; //initialize sliding window start
        for (int windowEnd = 0; windowEnd < s.length(); windowEnd++){ 
            
            currentChar = s[windowEnd];
            
            //contract the substring
            while (characters.find(currentChar) != characters.end()){
                pastChar = s[windowStart];
                characters.erase(pastChar);
                windowStart++;
            }
            
            //expand the substring
            characters[currentChar] = 0;
            
            currentLength = characters.size();
            if (currentLength > maxLength) maxLength = currentLength;
            
        }
        
        return maxLength;
        
    }
};
