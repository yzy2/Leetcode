class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> mmap;
        vector<int> output;
        
        for(int i = 1; i <= numbers.size(); i++){
            if(mmap.find(target - numbers[i-1]) != mmap.end()){
                output = {mmap[target - numbers[i-1]], i};
                return output;
            }
            else{
                mmap[numbers[i-1]] = i;
            }
        }
        return output;
        
    }
};