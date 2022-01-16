class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int m = questions.size();
        vector<pair<long long, long long>> dp(m, make_pair(0,0));
        vector<int> pos(m, 0);
        
        // dp.first -> if solve this question
        // dp.second -> if don't solve this question
        
        for(int i = m-1; i >=0; i--){
            if(i == m-1){
                dp[i].first = questions[i][0];
                dp[i].second = 0;
            }
            else{
                int x = questions[i][1] + i +1;
                if (x < m){
                    dp[i].first = questions[i][0] + max(dp[x].first, dp[x].second);
                }
                else{
                    dp[i].first = questions[i][0];
                }
               
                dp[i].second = max(dp[i+1].first,dp[i+1].second);   
            }
            
        }
        return max(dp[0].first, dp[0].second);
        
    }
};