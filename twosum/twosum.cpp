#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
      if (nums.size() < 2) exit(1);
      int goal;
      for (int i=0; i<nums.size(); i++){
        goal = target - nums.at(i);
        for (int j=i+1; j<nums.size(); j++){            
          if (nums.at(j) == goal) return {i, j};
        }
      }
      return {};
    }
};

int main() {
  std::vector<int> test = {2,3,4,5,6,7};
  int target = 9;
  Solution solution;
  std::cout << "[" << solution.twoSum(test, target).at(0) << ", " << solution.twoSum(test, target).at(1) << "]";
}
