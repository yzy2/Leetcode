class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, 0));
        for(auto &vec : dp){
            vec[0] = 1;
        }        
        for(int i = 0; i < coins.size(); i++){
            for(int j = 1 ; j<=amount; j++){
                if(i == 0){
                    if(j-coins[i] >= 0) dp[i][j] = dp[i][j-coins[i]]; 
                }
                else{
                    if(j-coins[i] >= 0){
                        dp[i][j] = dp[i-1][j] + dp[i][j-coins[i]];
                    }
                    else{
                        dp[i][j] = dp[i-1][j];
                    }
                } 
            }
        }

        return dp[coins.size()-1][amount];
    }
};
//           0     1     2     3     4      5 
// 1         1     1     1     1     1      1
// 1,2       1     1     2     2     3      3
// 1,2,5     1     1     2     2     3      4
              
// dp[i][j] = dp[i-1][j] + dp[i][j-coins[i]]