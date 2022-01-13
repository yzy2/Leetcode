class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> output;
        for(int i = 0; i < tasks.size(); ++i){
            tasks[i].push_back(i);
        }
        sort(tasks.begin(), tasks.end());
        
        long curr = 0;
        int i = 0;
        while(i < tasks.size() || !pq.empty()){
            if(pq.empty()){
                curr = max(curr, (long)tasks[i][0]);
            }

            while(i < tasks.size() && tasks[i][0] <= curr){
                pq.push(make_pair(tasks[i][1], tasks[i][2]));
                i++;
            }

            
            curr += (long)pq.top().first;
            output.push_back(pq.top().second);
            pq.pop();
            
                        
        }
        
        return output;
        
    }
};