class Solution {
public:
    bool wordPattern(string pattern, string s) {
        bool output = true;
        int m = pattern.size();
        unordered_map<string, char> s2p;
        vector<bool> p2s(26, false);
        string temp;
        int i = 0;
        s+=' ';
        for(char &c : s){
            if(c == ' '){
                auto it = s2p.find(temp);
                if(i >= m){
                    output = false;
                    break;
                }
                else if(it == s2p.end()){
                    if(!p2s[pattern[i]-'a']){
                        s2p[temp] = pattern[i];
                        p2s[pattern[i]-'a'] = true;
                    }else{
                        output = false;
                        break;
                    }
                    
                }else{
                    if(it->second != pattern[i]){
                        output =false;
                        break;
                    }
                }                          
                i++;
                temp = "";
            }else{
                temp+=c;    
            }
        }
        
        // different length
        if (i != m){
            output = false;
        }
        
        
        
        return output;
    }
};