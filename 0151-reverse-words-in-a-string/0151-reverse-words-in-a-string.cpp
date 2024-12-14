class Solution {
public:
    string reverseWords(string s) {
        deque<string>dq;
        stringstream ss(s);
        string temp;
        while(ss>>temp){
            dq.push_back(temp);
        }
        string ans;
        while(!dq.empty()){
            if(!ans.empty())ans+=' ';
            ans+=dq.back();
            dq.pop_back();
        }
        return ans;
    }
};