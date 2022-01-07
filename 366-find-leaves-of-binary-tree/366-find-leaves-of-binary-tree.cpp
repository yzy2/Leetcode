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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> output;
        
        dfs(root, output);
        
        return output;
    }
    
    int dfs(TreeNode* node, vector<vector<int>> &output){
        
        if(node == NULL){
            return 0;
        }
        
        int num = max(dfs(node->left, output), dfs(node->right, output))+1;
        
        if(num > output.size()){
            output.resize(num);
        }
        output[num-1].push_back(node->val);
        return num;
        
    }
    
};