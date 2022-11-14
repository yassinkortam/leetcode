class Solution {
    
private:
    
    int ansLength;
    string letters[10];
    
    vector<int> sToI(string digits){
        ansLength = 1;
        vector<int> ints;
        for (char digit : digits){
            ints.push_back(digit - 48);
            ansLength *= letters[digit - 48].length();
        }
        return ints;
    }
    
public:
    vector<string> letterCombinations(string digits) {
        
        //output
        vector<string> results;
        
        //edge case
        if (digits.length() == 0) return results;
            
        //Mapping numbers to letters
        letters[0] = "";
        letters[1] = "";
        letters[2] = "abc";
        letters[3] = "def";
        letters[4] = "ghi";
        letters[5] = "jkl";
        letters[6] = "mno";
        letters[7] = "pqrs";
        letters[8] = "tuv";
        letters[9] = "wxyz";
        
        //Converting digits to integer for convenience
        vector<int> intDigits = sToI(digits);
        set<string> permutations;
        
        //while the number of permutations is less than it mathematically should be
        while (permutations.size() < ansLength){
            
            string permutation = "";
            for (int digit : intDigits){
                
                //randomly guess next letter of the permutation
                permutation += letters[digit][rand()%letters[digit].length()];
            }
            //if a new permutation is found
            if (permutations.find(permutation) == permutations.end()){
                
                //save it
                results.push_back(permutation);
                permutations.insert(permutation);
            }
        }
        return results;
    }
};
