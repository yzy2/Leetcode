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
        // naive approach
        // vector<int> output;
        // getVec(root1, output);
        // getVec(root2, output);
        //sort(output.begin(), output.end());
        // inorder tree is ascending
        
        vector<int> output1;
        getVec(root1, output1);
        vector<int> output2;
        getVec(root2, output2);
        
        vector<int> output;
        int i = 0;
        int j = 0;
        while(i < output1.size() || j < output2.size()){
            
            if(i < output1.size() && j < output2.size()){
                
                if(output1[i] < output2[j]){
                    output.push_back(output1[i]);
                    i++;
                }else{
                    output.push_back(output2[j]);
                    j++;
                }
                
            }
            else if(i < output1.size()){
                output.push_back(output1[i]);
                i++;
            }
            else if(j < output2.size()){
                output.push_back(output2[j]);
                j++;
            }
        }
        
        
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