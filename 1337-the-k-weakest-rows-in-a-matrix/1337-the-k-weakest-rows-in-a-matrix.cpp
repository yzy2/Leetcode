class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        auto comp = [](const pair<int,int> &a, const pair<int,int> &b){
            if(a.first == b.first) return a.second > b.second;
            return a.first > b.first;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> pq(comp);
        
        vector<int> output;
        int m = mat.size();
        int n = (m != 0) ? mat[0].size() : 0;
        
        if(m == 0 || n == 0) return output;
        
        for(int i = 0; i < m; i++){
            int ct = 0;
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    break;
                }
                ct++;
            }
            pq.push(make_pair(ct, i));
        }
        
        for(int i = 0; i < k; i++){
            output.push_back(pq.top().second);
            pq.pop();
        }
        return output;
        
        
    }
};