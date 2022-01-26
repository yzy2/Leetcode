class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k == 0) return 0; 
        int hold[k];
        int sell[k];
        fill_n(hold, k, INT_MIN);
        fill_n(sell, k, 0);
        
        int hold_old[k];
        int sell_old[k];
        
        for(int price : prices){
            for(int i = 0; i < k; i++){
                hold_old[i] = hold[i]; //buy or skip
                sell_old[i] = sell[i]; //sell or skip
            }  
            
            
            for(int i = 0; i < k; i++){
                if(i == 0){
                    hold[i] = max(0-price, hold_old[i]); 
                }else{
                    hold[i] = max(sell[i-1]-price, hold_old[i]); //buy or skip
                }
                sell[i] = max(hold[i]+price, sell_old[i]); //sell or skip
            }

            
        }
        int output = 0;
        
        for(int i = 0; i < k; i++){
            output = max(output, sell[i]);
        }
        return output;
    }
};

// States
/*

hold[k][i] = max(sell[k-1][i]-price, hold[k][i-1]) //buy or skip
sell[k][i] = max(hold[k][i]+price, sell[k][i-1]) //sell or skip

*/
