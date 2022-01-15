class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> hset;
        int next=0;
        int output = 0;
        int temp = 0;
        for(int &num : nums){
            hset.insert(num);
        }
        

        for(int &num : nums){
            if(!hset.count(num-1)){
                // it is  start of sequence
                // see how long this sequence gets
                next = num;
                temp = 0;
                while(hset.count(next)){
                    ++next;
                    ++temp;
                }
                output = max(temp,  output);
            }
            
        }
        
        return output;
        
    }
};