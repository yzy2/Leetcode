class Solution {
public:
    vector<int> m_ct;
    Solution(vector<int>& w) {
        m_ct = {0}; 
        for(int i =0; i < w.size(); i++){
            m_ct.push_back(m_ct[i] + w[i]);
        }
    }
    
    int pickIndex() {
        int target = rand()%m_ct[m_ct.size()-1];
        // bfs Search 
        int beg, end, mid;
        beg = 0;
        end = m_ct.size()-1;
        while(beg < end){ // exclude m_ct[end] 
            mid = beg + (end-beg)/2;
            
            if(m_ct[mid] == target){
                return mid;
            }
            else if(target > m_ct[mid]){
                // because always exclude end, no bounds check needed
                if(target < m_ct[mid+1]){
                    return mid;
                }
                beg = mid+1;
                
            }else{
                // always excluding end so mid instead of mid -1
                end = mid;
            }
            
        }
        return 0;
    }
};
