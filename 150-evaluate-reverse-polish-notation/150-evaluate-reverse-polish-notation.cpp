class Solution {
public:
    
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int x, y;
        
        for(string &str : tokens){
            // No need for invalid check
            // Operation
            
            if(str == "+" || str == "-" || str == "*" || str == "/"){
                y = s.top(); s.pop();
                x = s.top(); s.pop();
                if(str == "+") s.push(x+y);
                else if (str == "-") s.push(x-y);
                else if (str == "*") s.push(x*y);
                else if (str == "/") s.push(x/y);
                    
            }
            else{
                s.push(stoi(str));
            }
        }
        return s.top();
    }
    
};