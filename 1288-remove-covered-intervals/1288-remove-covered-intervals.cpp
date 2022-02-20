class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        auto comp = [](vector<int> &a, vector<int> &b){
            return (a[0] == b[0]) ? a[1] > b[1] :a[0] < b[0];
        };
        sort(intervals.begin(), intervals.end(), comp);
        
        unordered_set<int> hset;
        int output = 0;
        for(int i = 0; i < intervals.size()-1; i++){
            for(int j = i+1; j < intervals.size(); j++){
                if(hset.find(j) != hset.end()){
                    continue;
                }
                else if(intervals[i][0] <= intervals[j][0] && intervals[i][1] >= intervals[j][1]){
                    hset.insert(j);
                    output++;
                }     
            }

        }
        return intervals.size() - output;
    }
};