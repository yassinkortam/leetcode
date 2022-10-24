class Solution {
private:
    struct Pointer{
        vector<int> array;
        int left;
        int right;
    };
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       
        double median;
        
        //pointers
        Pointer p1;
        Pointer p2;
        
        //position the pointers appropriately
        p1.array = nums1;
        p1.left = 0;
        p1.right = nums1.size() - 1;
        
        p2.array = nums2;
        p2.left = 0;
        p2.right = nums2.size() - 1;
        
        //edge case empty array
        if (p1.right == -1) p1 = p2;
        if (p2.right == -1) p2 = p1;
        if (p1.right == -1 && p2.right == -1) return -1;
        
        //store values
        int v1;
        int v2;
        
        //while not passing median 
        while (p1.left != p1.right || p2.left != p2.right){
            
            //shifting left pointer
            if (p1.array.at(p1.left) < p2.array.at(p2.left)){
                if (p1.left < p1.array.size() - 1){p1.left++; v1 = p1.array.at(p1.left);}
            }else {
                if (p2.left < p2.array.size() - 1){p2.left++; v1 = p2.array.at(p2.left);}
            }
            //shifting right pointer
            if (p1.array.at(p1.right) > p2.array.at(p2.right)){
                if (p1.right > 0){p1.right--; v2 = p1.array.at(p1.right);}
            }else {
                if (p2.right > 0){p2.right--; v2 = p2.array.at(p2.right);}
            }
        }
        
        median = (v1 + v2)*0.5;
        return median;
            
    }
};
