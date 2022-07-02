class Solution {
public:
    string decodeString(string s) {
        int n=s.size(),k;
        stack<string>st;
        string a,b;
        for(int i=0;i<n;i++){
            if(s[i]>='0'&&s[i]<='9')a+=s[i];
            else if(s[i]=='['){
                st.push(b);
                st.push(a);
                a=b="";
            }
            else if(s[i]==']'){
                int k=stoi(st.top());st.pop();
                string prev=st.top();st.pop();
                while(k--){
                    prev+=b;
                }
                b=prev;
            }
            else b+=s[i];
        }
        return b;
    }
};