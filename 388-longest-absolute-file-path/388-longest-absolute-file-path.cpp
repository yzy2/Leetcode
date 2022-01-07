class Solution {
public:
    int lengthLongestPath(string input) {
        vector<int> tabS; 
        int output = 0;
        int tabCt = 0; 
        bool isFile = false;
        string temp = ""; 
        
        for(int i = 0; i < input.size(); ++i){
            if(input[i] == '\n'){
                int num;
                // evaluate
                if(isFile){
                    num = temp.size();
                    if(tabCt > 0){
                        num+=tabS[tabCt-1];
                    }
                    output = max(output, num);
                }else{
                    num = temp.size() + 1;
                    
                    if(tabCt >= tabS.size()){
                        tabS.resize(tabCt+1);
                    }      
                    
                    if(tabCt > 0){
                        num+=tabS[tabCt-1];
                    }
                    tabS[tabCt] = num;
                }
                
                // reset
                isFile = false;
                tabCt = 0;
                temp = "";
            }
            else if(input[i] == '\t'){
                tabCt++;
            }else{
                if(input[i] == '.'){
                    isFile = true;
                }
                temp += input[i];
            }
            
        }
        
        // account for end of loop process
        if(isFile){
            int num = temp.size();
            if(tabCt != 0){
                num+=tabS[tabCt-1];
            }
            output = max(output, num);
        }
        
        return output;
    }
};