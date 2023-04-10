class Trie {
private:
    static const int MAX_CHAR=26;
    Trie* child[MAX_CHAR];
    bool isLeaf=0;
public:
    Trie() {
        memset(child,0,sizeof child);
    }
    
    void insert(string word,int idx=0) {
        if(idx==word.size()){
            isLeaf=1;
            return;
        }
        int cur=word[idx]-'a';
        if(!child[cur])
            child[cur]=new Trie();
        child[cur]->insert(word,idx+1);
    }
    
    bool search(string word,int idx=0) {
        if(idx==word.size())
            return isLeaf;
        int cur=word[idx]-'a';
        if(!child[cur])
            return 0;
        return child[cur]->search(word,idx+1);
    }
    
    bool startsWith(string word,int idx=0) {
        if(idx==word.size())
            return 1;
        int cur=word[idx]-'a';
        if(!child[cur])
            return 0;
        return child[cur]->startsWith(word,idx+1);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */