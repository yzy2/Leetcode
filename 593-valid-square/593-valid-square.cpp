class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        
        //Check for unique points
        set<vector<int>> unique;
        unique.insert(p1);
        unique.insert(p2);
        unique.insert(p3);
        unique.insert(p4);
        
        int i = 0;
        for(auto &e : unique){
            i++;
        }
        if(i != 4) return false;
        
        unordered_map<int, int> hmap;
        
        hmap[distSq(p1, p2)]++;
        hmap[distSq(p1, p3)]++;
        hmap[distSq(p1, p4)]++;
        hmap[distSq(p2, p3)]++;
        hmap[distSq(p2, p4)]++;
        hmap[distSq(p3, p4)]++;
        
        bool diag = false;
        bool edge = false;
        for(auto &key : hmap){
            if(key.second ==2){
                diag = true;
            }
            if(key.second ==4){
                edge = true;
            }
        }
        
        return (diag && edge);
        
    }
    
    int distSq(vector<int>& p1 ,vector<int>& p2){
            
        return (p1[0] - p2[0]) *  (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
        
    }
};