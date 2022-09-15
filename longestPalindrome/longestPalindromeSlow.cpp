class Solution {
public:
    
    //check if substring is a palindrome in O(n/2) ~ O(n) time
    bool isPalindrome(string s); 
    
    //returns longest palindrome substring in O(n^2) time
    string longestPalindrome(string s); 
    
};

bool Solution::isPalindrome(string s){ 
    for (int i = 0; i < s.length()/2; i++){ 
        if (s[i] != s[s.length() - 1 - i]) return false;
    }
    return true;
}

string Solution::longestPalindrome(string s) {
    
    int windowStart = 0, windowLength = 0; //characteristics of each for loop iteration's chosen substring
    int maxStart = 0, maxLength = 0; //characteristics of the longest palindromic substring
    
    //characteristics of each case's substring
    int case1Start, case1Length;
    int case2Start, case2Length;
    
        
    for (int windowMiddle = 0; windowMiddle < s.length(); windowMiddle++){ //sliding window implementation, incrementing center character
            
        
        //case 1: there are an odd number of characters in the palindrome substring
        case1Start = windowMiddle - 1; //base start for case 1
        case1Length = 3; //base length for case 1
        while(case1Start >= 0 && case1Length <= s.length()){ //while start and length are not out of index
            
            //if still palindromic, expand the substring on both sides
            if(isPalindrome(s.substr(case1Start, case1Length))){case1Start--; case1Length += 2;}
            else break;
        }
        //remove base cases from result
        case1Start += 1; 
        case1Length -= 2;
        
        
        //case 2: there are an even number of characters in the palindrome substring 
        case2Start = windowMiddle - 1; //base start for case 2
        case2Length = 2; //base length for case 2
        if (case2Start >= 0 && case2Length <= s.length()){ //if these values are valid
            
            if (s[case2Start] == s[windowMiddle]){ //if there is a pair of equal values in substr
                
                //account for the pair.
                case2Start--;
                case2Length += 2; 
                
                while(case2Start >= 0 && case2Length <= s.length()){ //while start and length are not out of index
            
                    if(isPalindrome(s.substr(case2Start, case2Length))){case2Start--; case2Length += 2;} //if still palindromic, expand the substring on both sides
                    else break;
                }
            }   
        }
        //remove base cases from result
        case2Start++;
        case2Length -= 2;   
        
        
        //pick the case with the longest substring
        if (case1Length > case2Length){windowStart = case1Start; windowLength = case1Length;}
        else {windowStart = case2Start; windowLength = case2Length;}
        
        //compare to max
        if (windowLength > maxLength){maxStart = windowStart; maxLength = windowLength;}
          
    }
    
    return s.substr(maxStart,maxLength); //return the longest substr given its details
}
