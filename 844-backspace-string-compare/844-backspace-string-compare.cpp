class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>ss,st;
        for(auto&it:s){
            if(it=='#'){
                if(!ss.empty())ss.pop();
            }
            else{
                ss.push(it);
            }
        }
        for(auto&it:t){
            if(it=='#'){
                if(!st.empty())st.pop();
            }
            else{
                st.push(it);
            }
        }
        return ss==st;
    }
};