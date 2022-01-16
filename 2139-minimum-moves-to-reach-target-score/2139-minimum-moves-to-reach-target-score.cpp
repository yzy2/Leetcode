class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int temp = target;
        int output = 0;
        
        if(target == 1) return 0;
        int i = 0;        
        
        while(temp > 0 && maxDoubles > 0){
            if(temp%2 ==1){
                ++output;
                --temp;
            } 
            if(temp == 0) break;
            
            temp = temp/2;
            --maxDoubles;
            ++output;
        }
        
        output += (temp-1);
        return output;
        
        
    }
};