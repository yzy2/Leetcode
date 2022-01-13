class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != s1.size() + s2.size()){
            return false;
        }
        vector<vector<bool>> dp(s1.size(), vector<bool>(s2.size(), true));
        return bfs(s3, 0, 0, s1, s2, dp);
        
    }
    
    bool bfs(string &s3, int i, int j, string &s1, string &s2, vector<vector<bool>> &dp){
        
        if(i == s1.size() && j == s2.size()){
            return true;
        }
        
        if(i < s1.size() && j < s2.size() && dp[i][j] == false) return false;
        
        
        if(i < s1.size() && s1[i] == s3[i+j] && bfs(s3, i+1, j, s1, s2, dp))
            return true;
        if(j < s2.size() && s2[j] == s3[i+j] && bfs(s3, i, j+1, s1, s2, dp))
            return true;
        
        if(i < s1.size() && j < s2.size())
            dp[i][j] = false;
        
        return false;
        
    }
    
    
};