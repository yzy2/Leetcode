class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> output;
    
        string temp = "";
        for(int i =0; i < s.size(); i++){
            if(i%k == 0 && temp.size() > 0){
                output.push_back(temp);
                temp = "";
            }
            temp += s[i];
        }
        if(temp.size() > 0){
            int f = k - temp.size();
            for(int i = 0; i < f; i++){
                temp.push_back(fill);
            }
            output.push_back(temp);
        }        
    
        return output;
    }
    
};