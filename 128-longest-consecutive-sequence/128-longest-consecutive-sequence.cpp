class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> hset;
        
        for(int &num : nums){
            hset.insert(num);
        }
        
        int next;
        int output = 0;
        for(int &num : nums){
            
            if(hset.find(num-1) ==  hset.end()){
                // it is  start of sequence
                // see how long this sequence gets
                next = num;
                int temp = 0;
                while(hset.find(next) != hset.end()){
                    ++next;
                    ++temp;
                }
                output = max(temp,  output);
            }
            
        }
        
        return output;
        
    }
};