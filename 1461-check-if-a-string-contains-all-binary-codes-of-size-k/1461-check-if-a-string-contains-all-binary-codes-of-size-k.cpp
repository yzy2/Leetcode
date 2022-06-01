class Solution {
public:
    bool hasAllCodes(string s, int k) {
        // Create hash-map for all binary code for K
        unordered_set<long long> uset;
        long long ret = pow(2,k);
        
        int l = 0;
        long long temp = 0;
        long long mask = ~(1 << k);
        for(int r = 0; r < s.size(); r++){
            temp = (temp << 1) + ((s[r] == '1') ? 1 : 0);
            if(r-l == k-1){
                temp &= mask;
                if(uset.find(temp) == uset.end()){
                    uset.insert(temp);
                    ret--;
                }
                l++;            
            }          
        }
        return (ret==0);
    }
};