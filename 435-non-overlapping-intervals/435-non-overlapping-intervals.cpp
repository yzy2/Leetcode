class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        auto comp = [](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        };
        sort(intervals.begin(), intervals.end(), comp);
        int output = 0;
        int i = 0;
        while(i < intervals.size()){
            int j = i +1;
            while(j < intervals.size() && intervals[j][0] < intervals[i][1]){
                j++;
            }
            i = j;
            output++;
            
        }
        return intervals.size() - output;
        
    }
};