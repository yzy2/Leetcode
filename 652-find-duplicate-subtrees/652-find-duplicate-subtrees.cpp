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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> output;
        unordered_map<string, int> hmap;
        dfs(root, hmap, output);
        
        return output;
    }
    
    string dfs(TreeNode* node, unordered_map<string, int> &hmap, vector<TreeNode*> &output){
        
        if(!node){
            return "";
        }
        
        string str = to_string(node->val)+"-<"+dfs(node->left, hmap, output)+"->"+dfs(node->right, hmap, output);
        
        hmap[str]++;
        if(hmap[str] == 2) output.push_back(node);
        
        
        return str;
    }
    
};