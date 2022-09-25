/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        int maxWidth=0;
        if(!root) return maxWidth;
        
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        
        while(!q.empty()){ //until an empty level is reached
            
            int queueSize = q.size();
            int startIndex = q.front().second;
            int endIndex = q.back().second;
            int currentWidth = endIndex - startIndex + 1;
            maxWidth = max(currentWidth, maxWidth);
            
            while(queueSize--){ //while the level hasn't been fully indexed
                
                //the front of the queue is initially the leftmost node of the next level at termination of the while loop
                //the back of the queue is the rightmost node of the next level at termination of the while loop
                
                //get the index of the leftmost parent node with unindexed children. 
                TreeNode* temp = q.front().first; 
                long index = q.front().second; //long due to overflow problems with int
                q.pop(); //remove parents from the queue
                
                //push children with appropriate indexes to the back of the queue, left to right
                if(temp->left) q.push({temp->left, 2*index + 1});
                if(temp->right) q.push({temp->right, 2*index + 2});
                
            }
            
        }
        return maxWidth;
    }
};
