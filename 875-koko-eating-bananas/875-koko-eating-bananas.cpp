class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int upperbound = 0;
        int lowerbound = 0;
        long long sum = 0;
        int output = INT_MAX;
        
        for(int &i : piles){
            sum+=(long long)i;
            upperbound = max(i, upperbound);
        }
        lowerbound = (int)(sum/((long long)h) + 0.5);
        
        int beg = max(lowerbound, 1);
        int end = max(upperbound, 1);
        int mid;
        // int ot;
        // for(int mid = 1; mid <= end; mid++){
        //     int temp = h;
        //     bool work = true;
        //     ot = mid;
        //     for(int &num : piles){
        //         temp -= (num+mid-1)/mid;
        //         if(temp < 0){
        //             work = false;
        //             ot = INT_MAX;
        //             break;
        //         }
        //     }
        //     output = min(ot, output);
        // }

        while(beg <= end){
            mid = beg + (end-beg)/2;            
            int temp = h;
            bool work = true;
            for(int &num : piles){
                temp -= (num+mid-1)/mid;
                if(temp < 0){
                    work = false;
                    break;
                }
            }
            
            if(work){
                end = mid-1;
                output = min(mid, output);
            }
            else{
                beg = mid+1;
            }
            
        }
        return output;
        
        
    }
};