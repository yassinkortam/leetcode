class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mynums;
        vector <int> solution;
        for (int i=0; i<nums.size(); i++){
            mynums[nums[i]] = i;
        }
        for (int i=0; i<nums.size(); i++){
            int temp = target - nums[i]; 
            if (mynums.find(temp) != mynums.end()){
                if (mynums[temp] != i){
                    solution.push_back(mynums[temp]);
                    solution.push_back(i);
                    break;
                }
            }      
        }
        return solution;
    }
};
