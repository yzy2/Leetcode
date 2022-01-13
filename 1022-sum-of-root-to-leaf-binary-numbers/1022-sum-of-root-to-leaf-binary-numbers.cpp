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
    int sumRootToLeaf(TreeNode* root) {
        int output = 0;
        helper(root, 0, output);
        return output;
        
    }
    void helper(TreeNode* root, int curr, int& output){
        
        if(!root){
            
            return;
        }
        
        if(!root->left && !root->right){
            output += (curr << 1) + root->val;
            return;
        }
        
        
        helper(root->left, (curr << 1) + root->val, output);
        helper(root->right, (curr << 1) + root->val, output);
        
    }
    
};