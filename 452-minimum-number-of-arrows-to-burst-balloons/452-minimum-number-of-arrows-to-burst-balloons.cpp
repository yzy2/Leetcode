class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int count = 0;
        int i = 0;
        while(i < points.size()){
            int j = i + 1;
            while(j < points.size() && points[i][1] >= points[j][0]){
                points[i][0] = max(points[i][0], points[j][0]);
                points[i][1] = min(points[i][1], points[j][1]);
                j++;    
            }
            i = j;
            count++;
        }
        return count;
        
    }
};