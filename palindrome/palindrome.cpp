#include <iostream>
#include <cmath>

class Solution {
public:
    bool isPalindrome(int x) {
      if (x < 0) return false;
      if (x < 10) return true;
      int n = -1;
      int dummy = x;
      while (dummy > 0){dummy/=10;n++;}
      int i = 0;
      int left;
      int right;
      while (i < n){
        left = (x/(int)pow(10, n-i))%10;
        right = (x%(int)pow(10, i+1))/(int)pow(10, i);
        if (left != right) return false;
        i++;
      }
      return true;
    }
};

int main(){
  Solution solution;
  std::cout << solution.isPalindrome(22) << std::endl;
}
