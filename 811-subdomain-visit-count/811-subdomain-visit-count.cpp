class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> ctMap;
        
        int count;
        string domain;
        bool d = false;
        for(string &s : cpdomains){
            // process count
            domain = "";
            vector<string> sv;
            for(char &c : s){
                if(c == ' '){
                   count = stoi(domain);  
                   domain = "";
                }
                else if(c == '.'){
                    for(string &ds : sv){
                        ds+= '.' + domain;
                    }
                    sv.push_back(domain);
                    domain = "";
                }else{
                    domain+=c;
                }
            }
            if(domain.size() > 0){
                for(string &ds : sv){
                    ds+= '.' + domain;
                }
                sv.push_back(domain);
                domain = "";
            }
            
            // process all subdomain and add count to each
            for(string &str : sv){
                ctMap[str]+=count;
            }
            
        }
        
        // loop through all element in ctMap and create output string
        vector<string> output;
        string temp;
        for(auto &it : ctMap){
            temp = "";
            temp = to_string(it.second) + ' ';
            temp += it.first;
            output.push_back(temp);
        }
        
        
        return output;
    }
};