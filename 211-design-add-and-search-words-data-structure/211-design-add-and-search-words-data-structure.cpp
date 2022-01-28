class WordDictionary {
public:
    
    class TrieNode{
    public:
        TrieNode* next[26];
        bool endWord;
        TrieNode(){
            for(int i = 0; i < 26; i++){
                this->next[i] = NULL;
            }
            endWord = false;
        }
        
    };

    TrieNode *root;
    WordDictionary() {
        root= new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* temp = root;
        // Building Trie
        for(char &c : word){
            if(!temp->next[c-'a']){
                temp->next[c-'a'] = new TrieNode();
            }
            temp = temp->next[c-'a'];
        }
        temp->endWord = true;
    }
    
    bool search(string word) {
        TrieNode* temp = root;
        return recurSearch(word, temp);
    }
    
    bool recurSearch(string word, TrieNode *temp){
        bool output = true;
        for(int i = 0 ; i < word.size(); i++){

            if(word[i] == '.'){
                // recursive search until first match
                for(int j = 0; j < 26; j++){
                    if(temp->next[j] != NULL){
                        string stemp = (i == word.size()-1) ? "" :word.substr(i+1);
                        output = recurSearch(stemp, temp->next[j]);
                        if(output) return true;
                    }
                }
                return false;
            }
            else if(temp->next[word[i]-'a'] != NULL){
                temp = temp->next[word[i]-'a'];
            }else{
                return false;
            }
        }
        // check if temp is the last word
        if(!temp->endWord) output = false;
        return output;
    }
    
    
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */