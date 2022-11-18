class Solution {
private:
    unordered_map<int,int> mynums;
    
    void loadData(vector<int> nums){
        for (int num : nums){
            if (mynums.find(num) == mynums.end()){
                mynums[num] = 1;
            }
            else{
                mynums[num]++;
            }
        }
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        //solution
        vector<vector<int>> solution;
        
        //store all nums and their occurences in a hashmap
        sort(nums.begin(), nums.end(), greater<int>());
        loadData(nums);
        
        //edge case
        if (nums[nums.size() -1] > 0) return solution;
        
        //store previous triplets
        set<set<int>> triplets;
        
        for(int i=0; i<nums.size()-1; i++){
            int num1 = nums[i];
            int num2;
            int num3;
            for (int j = nums.size() -1; j > i; j--){
                num2 = nums[j];
                num3 = (num1 + num2)*-1;
                
                //uniqueness check
                if (i == j) break;
                if (num1 == num3 || num2 == num3)
                    if (mynums.find(num3) != mynums.end())
                        if (mynums[num3] == 1)
                            continue;
                if (num1 == num3 && num2 == num3)
                    if (mynums.find(num3) != mynums.end())
                        if (mynums[num3] == 2)
                            continue;
                
                if (mynums.find(num1) == mynums.end()) continue;
                if (mynums.find(num2) == mynums.end()) continue;
                if (mynums.find(num3) == mynums.end()) continue;
                
                vector<int> triplet;
                triplet.push_back(num1);
                triplet.push_back(num2);
                triplet.push_back(num3);
                
                set<int> save;
                save.insert(num1);
                save.insert(num2);
                save.insert(num3);
                
                if (triplets.find(save) == triplets.end()){
                    solution.push_back(triplet);
                    triplets.insert(save);
                }
            }
        }
        return solution;
    }
};
