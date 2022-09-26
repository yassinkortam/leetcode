class Solution {
public:
    int maxArea(vector<int>& height) {
        
        //traverse the array from the left and right 
        //hold onto a height unless the maximum possible area is exceeded by another
        
        int maxArea = 0;
        int leftIndex = 0;
        int rightIndex = height.size() - 1;
        
        while (leftIndex < rightIndex){ //avoid repetitive calculations
            
            int leftHeight = height.at(leftIndex);
            int rightHeight = height.at(rightIndex);
            int currentWidth = rightIndex - leftIndex;
            int currentArea = 0;
            
            if (leftHeight > rightHeight){ //left is tall, right is short
                
                currentArea = rightHeight*currentWidth;
                rightIndex--; //searching for a taller right side
                
            }
            else{ //right is tall, left is short. catches equal case.
                
                currentArea = leftHeight*currentWidth;
                leftIndex++; //searching for a taller left side
                
            }
            
            maxArea = max(currentArea, maxArea);
            
        }
    
        return maxArea;
        
    }
};
