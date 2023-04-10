class Solution {
private:
    class trie
    {
    private:
        static const int MAX_CHAR=26;
        trie* child[MAX_CHAR];
        int cnt=0;
    public:
        trie()
        {
            memset(child,0,sizeof child);
        }
        void insert_word(string word,int idx=0)
        {
            if(idx==(int)word.size())
            {
                return;
            }
            else
            {
                cnt++;
                int cur=word[idx]-'a';
                if(child[cur]==0)
                    child[cur]=new trie();
                child[cur]->insert_word(word,idx+1);
            }
        }
        string getLongestCommonPrefix(int length)
        {
            if(cnt!=length)
                return "";
            char ch;
            int can=0;
            for(int i=0; i<MAX_CHAR; i++)
                if(child[i]!=0)
                    can++,ch=char(i+'a');
            if(can==1)
                return ch+child[ch-'a']->getLongestCommonPrefix(length);
            else return "";
        }
    };
public:
    string longestCommonPrefix(vector<string>& strs) {
        trie root;
        int length=strs.size();
        for(int i=0;i<length;i++){
            root.insert_word(strs[i]);
        }
        return root.getLongestCommonPrefix(length);
    }
};