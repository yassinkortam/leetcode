class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        //use a sliding window of max length = longest word to find words
        
        //create a map of all the words and their repeats
        //save length of first word (all words same length)
        unordered_map <string, int> wordsMap;
        int substrLength = words[0].length();
        for (int i = 0; i < words.size(); i++){
            if (wordsMap.find(words.at(i)) == wordsMap.end()) wordsMap[words.at(i)] = 1;
            else{
                wordsMap[words.at(i)]++; //take note of repetition
                wordsMap[to_string(i)] = 0; //increment wordsMap size with dummy key
            }
        }
        
        vector<int> windowStarts; //store the starting indeces
        
        //each key in map represents a word
        //if there are any word repeats
        //reset substring starting index immediately
        unordered_map <string, int> windowWords; 
        int numWords = wordsMap.size(); //windowWords should be of this size
        
        string currentWord;
        int currentWordStart;
        bool pastWordNotInMap = true; //if currentWord is not a repeat
        for (int windowStart = 0; windowStart < s.length(); windowStart++){ //consider all possible reading frames
            
            currentWordStart = windowStart;
            
            while (windowWords.size() < numWords){ //don't stop until find 1 full substr
                if (currentWordStart + substrLength > s.length()) break; //index range check
                
                currentWord = s.substr(currentWordStart, substrLength); //find the current word
                
                //if word is in wordsMap
                if (wordsMap.find(currentWord) != wordsMap.end()){
                    
                    //if word not in current substr add it
                    if (windowWords.find(currentWord) == wordsMap.end()){
                        windowWords[currentWord] = 1;
                        
                        //if the substring is complete, save windowStart and start over
                        if (windowWords.size() == numWords){
                            cout << currentWord << "\n";
                            windowStarts.push_back(windowStart);
                            windowWords.clear();
                            break;
                        }
                      
                    //otherwise check the allowed repetitions
                    }else if (windowWords[currentWord] < wordsMap[currentWord]){
                        //if allowed, add the repetition
                        windowWords[currentWord]++;
                        //add a dummy key with integers to increment windowWords size
                        windowWords[to_string(currentWordStart)] = 0;
                        //if the substring is complete, save windowStart and start over
                        if (windowWords.size() == numWords){
                            windowStarts.push_back(windowStart);
                            windowWords.clear();
                            break;
                        }
                        
                    //otherwise start over
                    }else{windowWords.clear(); break;}
                        
                //otherwise start over
                }else{windowWords.clear(); break;}
                
                currentWordStart += substrLength;
                
            }//while loop
            
            //clear the reading frame
            windowWords.clear();
            
        }//for loop
        
        return windowStarts;
        
    }
};
