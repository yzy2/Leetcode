class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy= INT_MAX;
        int sell = 0;
        
        for(int &num : prices){
            int lastbuy = buy;
            int lastsell = sell;    
            buy = (lastbuy  < num) ? lastbuy : num;
            sell = max(lastsell, num-lastbuy);
        }
        return sell;
        
    }
};
// States
// Buy 
// Sell 