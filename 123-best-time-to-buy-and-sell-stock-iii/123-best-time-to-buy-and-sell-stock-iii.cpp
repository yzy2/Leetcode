class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int hold1_old=INT_MIN, sell1_old=0,hold2_old=INT_MIN, sell2_old=0;
        int hold1, sell1,hold2, sell2;
        for(int &price:prices){
                      
            hold1 = max(0-price, hold1_old);
            sell1 = max(hold1_old+price, sell1_old);
            hold2 = max(sell1_old-price, hold2_old);
            sell2 = max(hold2_old+price, sell2_old);
            
            hold1_old = hold1;
            sell1_old = sell1;
            hold2_old = hold2;
            sell2_old = sell2;
        }
        return max(sell1, sell2);
    }
};

// States
// hold1[k] = max(0-prices[k], hold1[k-1]) 
// sell1[k] = max(hold1[k-1] + prices, sell1[k-1])
// hold2[k] = max(sell1[k-1]-price, hold2[k-1])
// sell2[k] = max(hold2[k-1]+price, sell2[k-1])