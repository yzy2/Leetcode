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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        TreeNode* temp = root;
        if(!root) root = new TreeNode(val);
        while(temp){
            
            if(!temp->left && val < temp->val){
                temp->left = new TreeNode(val);
                break;
            }
            else if(!temp->right && val > temp->val){
                temp->right = new TreeNode(val);
                break;
            }
            
            if(val > temp->val){
                temp = temp->right;
            }else{
                temp = temp->left;
            }
            
        }
        return root;
    }
};