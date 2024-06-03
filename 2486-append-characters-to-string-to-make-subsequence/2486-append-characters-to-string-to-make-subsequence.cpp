class Solution {
public:
    int appendCharacters(string s, string t) {
        int j=0;
        for(auto&it:s){
            if(j==t.size())break;
             if(it==t[j])
                j++;
        }
        return t.size()-j;
    }
};