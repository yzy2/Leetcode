class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
    	long long output = 0;
    	int m = points.size();
    	int n = points[0].size();
    	
    	
//     	//O(M*N*N)
//     	vector<vector<long long>> dp(m, (vector<long long>(n, 0)));
//         // Start with top row
// 		for(int j = 0; j < n; j++){
// 			dp[0][j] = points[0][j];
// 		}
// 		long long maxct;
// 		for(int i = 1; i < m; i++){
// 			for(int j = 0; j<n; j++){
// 				maxct = 0;
// 				for(int k = 0; k < n; k++){
// 					maxct = max(maxct, (long long)((points[i][j] + dp[i-1][k]) - abs(j-k)));
// 				}
// 				dp[i][j] = maxct;
// 			}			
// 		}

// 		for(int j = 0; j < n; j++){
// 			output = max(output, (long long)dp[m-1][j]);
// 		}

        
        
        //O(M*N*N)
    	vector<vector<long long>> dp(m, (vector<long long>(n, 0)));
        // Start with top row
		for(int j = 0; j < n; j++){
			dp[0][j] = points[0][j];
		}
		long long maxct;
		for(int i = 1; i < m; i++){
            long long left = (long long)INT_MIN;
			for(int j = 0; j<n; j++){        
                left = max(left, dp[i-1][j] + j);
				dp[i][j] = max(dp[i][j], left + points[i][j] - j);
			}
            long long right = (long long)INT_MIN;
            for(int j = n-1; j>=0; j--){        
                right = max(right, dp[i-1][j] - j);
				dp[i][j] = max(dp[i][j], right + points[i][j] + j);
			}	
		}

		for(int j = 0; j < n; j++){
			output = max(output, (long long)dp[m-1][j]);
		}
        
        
		return output;

    }
};