class Solution {
public:
    int appendCharacters(string s, string t) {
        int j=0,m=t.size();
        for(auto&it:s){
            if(j==m)break;
             if(it==t[j])
                j++;
        }
        return m-j;
    }
};