class Solution {
private:
    //each index corresponds to a letter of the alphabet
    //each value corresponds to a variable that is equivalent to that letter
    int letterRelations[26];
    
    //union find algorithm
    int unionFind(int letter) {
        return letterRelations[letter] == letter ? letter : (letterRelations[letter] = find(letterRelations[letter]));
    }
    
public:
    bool equationsPossible(vector<string>& equations) {
        
        //populate the letterRelations array with the entire alphabet equal to itself
        for (int letter = 0; letter < 26; letter++) letterRelations[letter] = letter;
        
        for (auto e : equations) {
            //if two letters are equivalent, update the letterRelations array to store that equivalency
            if (e[1] == '=') letterRelations[unionFind(e[0] - 'a')] = unionFind(e[3] - 'a'); 
        }
        
        for (auto e : equations) {
            //if the unequal letters are part of the same group already, return false
            if (e[1] == '!' && unionFind(e[0] - 'a') == unionFind(e[3] - 'a')) return false;
        }
        
        return true;
        
    }
};
