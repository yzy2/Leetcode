class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        int l=0, r =0;
        int hist[26] = {0};
        int output = 0;
        
        for(r; r < s.size(); r++){
            hist[s[r]-'a'] ++;
            if(r-l+1 == k){
                // check
                bool found = true;  
                for(int i = 0; i < 26; i++){
                    if(hist[i] > 1) found = false;
                }
                if(found) output++;
                // move
                hist[s[l]-'a']--;
                l++;
            }   
        }
        return output;
    }
};