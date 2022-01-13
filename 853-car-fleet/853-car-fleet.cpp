class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        if(position.size() <= 1) return position.size();
        
        vector<pair<int, float>> arr; // position, timeToArrival
        for(int i = 0; i < position.size(); ++i){
            arr.push_back(make_pair(position[i], ((float)(target-position[i])/(float)speed[i])));
        }
        
        sort(arr.begin(), arr.end()); 
        
        stack<float> s; // stores time to arrival
        int output = 0;
        for(int i = arr.size() -1; i >=0; i--){
            
            if(s.empty()){
                s.push(arr[i].second);
                output++;
            }else{
                if(arr[i].second > s.top()) {
                    s.push(arr[i].second);
                    output++;
                }
            }
        }
        
        return output;
        
        
    }
};