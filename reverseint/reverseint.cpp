class Solution {
private:
    //reverse string in O(n) time
    string reverse(string str);
public:
    //reverse int in O(n) time
    int reverse(int x);
};

string Solution::reverse(string str){
    string reversed = "";
    for (int i=str.length()-1; i>=0; i--){
        reversed += str[i];
    }
    return reversed;
}

int Solution::reverse(int x){
    //remember the sign of the int
    int sign = 1; 
    if (x < 0) sign = -1;
    
    //cast the int to a string
    string str = to_string(x);
    
    //reverse the string
    str = reverse(str);
    
    //try to cast the string as a 32 bit signed int. if it fails, its too long and return 0.
    try{int integer = stoi(str); return sign*integer;}
    catch(exception out_of_range){return 0;}
}
