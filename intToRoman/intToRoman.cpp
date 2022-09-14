#include <unordered_map>
#include <string>

class Solution {
public:
    string intToRoman(int num) {
        //store all possible roman numerals in a map
        //subtract the largest roman number until result < roman number
        //subtract the appropriate roman subtraction number until result < roman number
        //repeat with different roman numerals until result is zero
        
        //all possible roman numerals
        unordered_map <int, string> intToRoman;
        intToRoman[1000] = "M";
        intToRoman[900] = "CM";
        intToRoman[500] = "D";
        intToRoman[400] = "CD";
        intToRoman[100] = "C";
        intToRoman[90] = "XC";
        intToRoman[50] = "L";
        intToRoman[40] = "XL";
        intToRoman[10] = "X";
        intToRoman[9] = "IX";
        intToRoman[5] = "V";
        intToRoman[4] = "IV";
        intToRoman[1] = "I";
        
        int mynum = num; //will work with mynum to preserve original num
        string roman = "";
        
        while (mynum > 0){
            if (mynum >= 1000) {mynum -= 1000; roman += intToRoman[1000];}
            else if (mynum >= 900) {mynum -= 900; roman += intToRoman[900];}
            else if (mynum >= 500) {mynum -= 500; roman += intToRoman[500];}
            else if (mynum >= 400) {mynum -= 400; roman += intToRoman[400];}
            else if (mynum >= 100) {mynum -= 100; roman += intToRoman[100];}
            else if (mynum >= 90) {mynum -= 90; roman += intToRoman[90];}
            else if (mynum >= 50) {mynum -= 50; roman += intToRoman[50];}
            else if (mynum >= 40) {mynum -= 40; roman += intToRoman[40];}
            else if (mynum >= 10) {mynum -= 10; roman += intToRoman[10];}
            else if (mynum >= 9) {mynum -= 9; roman += intToRoman[9];}
            else if (mynum >= 5) {mynum -= 5; roman += intToRoman[5];}
            else if (mynum >= 4) {mynum -= 4; roman += intToRoman[4];}
            else if (mynum >= 1) {mynum -= 1; roman += intToRoman[1];}
        }
        
        return roman;
        
    }
};
