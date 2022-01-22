class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<pair<char, int>> ss;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                ss.push_back(make_pair(s[i], i));
            }
            else if(s[i] == ')'){
                if(!ss.empty() && ss.back().first == '('){
                    ss.pop_back();
                }else{
                    ss.push_back(make_pair(s[i], i));
                }
            }
            
        }
        string output = "";
        int j = 0;
        for(int i = 0; i < s.size(); i++){
            
            if(j>= ss.size() || i != ss[j].second){
                output += s[i];    
            }else{
                j++;
            }
            
        }
        return output;
    }
};