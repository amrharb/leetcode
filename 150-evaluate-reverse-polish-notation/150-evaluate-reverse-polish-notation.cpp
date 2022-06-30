class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto&it:tokens){
            if(it[0]>=48||it.size()>1){
                st.push(stoi(it));
            }
            else{
                int a=st.top();st.pop();
                int b=st.top();st.pop();
                if(it=="+")st.push(a+b);
                else if(it=="-")st.push(b-a);
                else if(it=="*")st.push(a*b);
                else st.push(b/a);
            }
        }
        return st.top();
    }
};