class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> hmap; // count, position
        int output = 0;
        int count = 0;
        hmap[0] = 0;
        for(int i = 0; i < nums.size(); i++){
            count += (nums[i] == 0) ? -1 : 1; // -1 for 0, +1 for 1
            if(hmap.find(count) != hmap.end()){
                // this count exists, meaning the array in between is a balanced array
                if(count == 0){
                    output = max(output, i+1);
                }else{
                    output = max(output, i-hmap[count]);
                }
                
            }else{
                // only take  first occurance
                hmap[count] = i;
            }
            
        }
        return output;
    }
};

