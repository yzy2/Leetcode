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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        vector<int> output;
        getVec(root1, output);
        getVec(root2, output);
        sort(output.begin(), output.end());
        return output;
        
    }
    void getVec(TreeNode* root, vector<int> &output){
        
        if(!root){
            return;
        }
        getVec(root->left, output);
        output.push_back(root->val);
        getVec(root->right, output);
    }
};