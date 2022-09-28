class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> solution;
        int leftNumber, rightNumber;
        
        //j increments the larger value of the sum
        int j = numbers.size() - 1;
        
        //i increments the smaller value of the sum
        for (int i = 0; i< numbers.size(); i++){
            
            //if entire vector was traversed without solution, return empty vector
            if (j < 0) return solution;
            
            leftNumber = numbers.at(i);
            rightNumber = numbers.at(j);
            int sum = leftNumber + rightNumber;
            
            //pick the next largest number for the sum
            //keep the smaller number in the sum the same
            if (sum > target){i--; j--;}
            
            //if target is found return solution
            if (sum == target){
                solution.push_back(i + 1);
                solution.push_back(j + 1);
                return solution;
            }       
        }
        
        //if entire vector was traversed without solution, return empty vector
        return solution;
    }
};
