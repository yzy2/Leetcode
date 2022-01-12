class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Sliding window
        
        int output=0;
        int temp = 0;
        int p1=0;
        int p2=0; 
        unordered_map<char, int> wordCt;
        
        
        while(p2 < s.size()){
            
            char word = s[p2];
            
            wordCt[word]++;
            
            temp++;
            
            if(wordCt[word] > 1){
                // found dup, move p1
                while(s[p1] != word){
                    wordCt[s[p1]]--;
                    p1++;
                    temp--;
                }
                wordCt[s[p1]]--;
                temp--;
                p1++;
            }
            output = max(output, temp);
            p2++;   
            
            
        }
        
        return output;
        
        
    }
};