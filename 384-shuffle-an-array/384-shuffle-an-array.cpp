class Solution {
public:
    vector<int> m_nums;
    vector<int> default_nums;
    Solution(vector<int>& nums) {
        default_nums = nums;
        m_nums = nums;
    }
    
    vector<int> reset() {
        return default_nums;
    }
    
    vector<int> shuffle() {
        int ran, temp;
        
        for(int i = 0; i<m_nums.size(); ++i){
            ran = rand()%m_nums.size();
            swap(m_nums[i], m_nums[ran]);
        }
        
        return m_nums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */