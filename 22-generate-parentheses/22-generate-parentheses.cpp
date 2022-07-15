class Solution {
public:
    bool check(string s){
        int cnt=0;
        for(auto&it:s){
            if(it=='(')cnt++;
            else cnt--;
            if(cnt<0)return 0;
        }
        return !cnt;
    }
    vector<string> generateParenthesis(int n) {
        vector<string>str;
        n*=2;
        for(int i=0;i<(1<<n);i++){
            bitset<16>s(i);
            string x;
            for(int j=0;j<n;j++){
                if(s[j])x+='(';
                else x+=')';
            }
            if(check(x))str.push_back(x);
        }
        return str;
    }
};