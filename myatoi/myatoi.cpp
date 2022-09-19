class Solution {
public:
  //note that leetcode didn't accept this because I cropped overflow in base 10 instead of binary, too lazy to do binary at the moment.
    int myAtoi(string s) {
        
        const int max = 147483648; //32 bit max ommitting first 2 to avoid overflow error
        int sign = 1, magnitude = 0, digit, place = 1;
        string number = ""; //clean number
        
        //43, 45, 48-57 , everything else goes away
        for (int pos = 0; pos < s.length(); pos++){ //clean up the number
            if (s[pos] != 43)
                if (s[pos] != 45)
                    if (s[pos] < 48 || s[pos] > 57)
                        //problem wants this for some reason
                        if (s[pos] >= 'A' && s[pos] <= 'z') 
                            if (number.length() == 0) return 0; 
                            else continue;
            if (s[pos] != 32) number += s[pos];
        }
        
        cout << number; 
        
        for (int pos = number.length() - 1; pos >= 0; pos--){
            
            if (pos == 0){ //check the first character for sign only once
                if (number[pos] == 45){sign = -1; continue;} //check  for negative
                if (number[pos] == 43){sign = 1; continue;} //check  for positive
            }
            
            digit = number[pos] - 48; //ASCII adds 48 to the actual value 
            
            if (place <= 1E8) {digit *= place;  place *= 10;}
            else break;
            
            magnitude += digit; //adding place value to integer
        }
        
        return sign*magnitude;
        
        
    }
};
