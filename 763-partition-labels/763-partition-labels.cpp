class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> hmap;
        for(int i = s.size()-1; i >=0; i--){
            if(hmap.find(s[i]) == hmap.end()){
                // store last position
                hmap[s[i]] = i;
            }
        }
        vector<int> output;
        int r = 0;
        int last_pos = -1;
        int num = 1;
        while(r < s.size()){  
            last_pos = max(last_pos, hmap[s[r]]);
            if(last_pos == r){
                output.push_back(num);
                num = 0;
            }
            
            num++;
            r++;
        }
        return output;
    }
};