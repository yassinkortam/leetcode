class Solution {
public:
    int longestValidParentheses(string s) {
        
        //saving open and close paranthesis for simplicity
        char open = '(', close = ')';
        
        int numOpen = 0;
        int currentLength = 0, maxLength = 0;
        
        //sweep from the left
        for (int i = 0; i < s.length(); i++){
            
            if (s[i] == open) numOpen++; //keep track of unpaired open parantheses
            else if (s[i] == close)
                if (numOpen > 0){ //if there are unpaired open parantheses
                    currentLength += 2; //account for the length of the pair: 2
                    numOpen--; 
                    if (numOpen == 0) 
                        //if that was the last unpaired parantheses, update maxLength
                        maxLength = max(currentLength, maxLength); 
                }
                //if there is an excess of close, then move on to next substr
                else currentLength = 0;
            
        }
        
        //the loop above does not account for excess open parantheses preceding a valid substr
        //it will default to zero in that case, which is helpful since it wont make a false max
        //however, it does account for excess close parantheses, so it can be easily modified
        //just reverse the direction of traversal and track close parantheses instead
        //if a longer substr is found in this direction, update maxLength
        
        int numClose = 0; 
        currentLength = 0; //reset current substr length
        
        //sweep from the right
        for (int i = s.length() - 1; i >= 0; i--){//all I did after this is replace close with open v/v.
            if (s[i] == close) numClose++;
            else if (s[i] == open)
                if (numClose > 0){
                    currentLength += 2; 
                    numClose--;
                    if (numClose == 0) 
                        maxLength = max(currentLength, maxLength);
                }
                else currentLength = 0;
        }
        
        return maxLength;
    }
};
