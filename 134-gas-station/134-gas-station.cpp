class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // Brute force O(N^2)    	
//     	int output = -1;
//     	int m = gas.size();
//     	for(int num = 0; num < gas.size(); ++num){
// 	 		int curr = num;
// 	    	int tank = 0;
// 	    	bool passed = true;
// 	    	for(int i = 0; i < m; i++){
// 				curr = (num + i) % m;
// 	    		tank+=gas[curr];
// 	    		if(tank < cost[curr]){
// 	    			passed = false;
// 	    			break;
// 	    		}
// 	    		tank-=cost[curr];
// 	    	}
// 	    	if(passed){
// 	    		output = num;
// 	    		break;
// 	    	}

//     	}
//     	return output;

        // Memorization/DP O(N + C)
        int output = 0;
        int curr = 0;
        int sum = 0;
        for(int i = 0; i < gas.size(); ++i){
            curr += gas[i] - cost[i];
            sum += gas[i] - cost[i];
            if(curr < 0){
                curr = 0;
                output = i+1;
            }   
        }
        if(sum < 0) output = -1;
        return output;
    }
};