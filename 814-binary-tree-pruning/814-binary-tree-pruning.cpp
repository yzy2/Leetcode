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
    TreeNode* pruneTree(TreeNode* root) {
        if(!helper(root)){
            root=NULL;
        };
        
        return root;
    }
    bool helper(TreeNode* root){
        bool val = false;
        if(root == NULL){
            return val;
        }
        if(root->val == 1){
            if(!helper(root->left))root->left = NULL;

            if(!helper(root->right))root->right = NULL;
            return val = true;
        }
        bool leftv = helper(root->left);
        bool rightv = helper(root->right);
        
        if(!leftv) root->left = NULL;
        if(!rightv) root->right = NULL;
        
        return leftv || rightv;
        
    }
};