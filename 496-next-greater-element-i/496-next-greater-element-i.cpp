class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& a, vector<int>& b) {
        int n=a.size(),m=b.size();
        vector<int>v(m,-1),ans(n,-1);
        stack<int>st;
        map<int,int>mp;
        for(int i=0;i<m;i++){
            mp[b[i]]=i;
            while(!st.empty()&&b[st.top()]<b[i]){
                v[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        for(int i=0;i<n;i++){
            auto it=mp.lower_bound(a[i]);
            if(it==mp.end()||(*it).first!=a[i]||v[mp[a[i]]]==-1)ans[i]=-1;
            else ans[i]=b[v[mp[a[i]]]];
        }
        return ans;
    }
};