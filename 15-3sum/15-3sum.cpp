class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        int n=v.size();
        vector<vector<int>>ans;
        sort(v.begin(),v.end());
        map<int,vector<int>>mp;
        set<vector<int>>st;
        for(int i=0;i<n;i++)mp[v[i]].push_back(i);
        for(int i=0;i<n;i++){
           if(i&&v[i]==v[i-1])continue;
           for(int j=i+1;j<n;j++){
               if(j>i+1&&v[j]==v[j-1])continue;
              if(mp.find(-v[i]-v[j])!=mp.end()){
                for(auto&it:mp[-v[i]-v[j]]){
                    if(it!=i&&it!=j){
                        vector<int>x={v[i],v[j],-v[i]-v[j]};
                        sort(x.begin(),x.end());
                        st.insert(x);
                        break;
                    }
                }
            }
        }
    }
    ans=vector<vector<int>>(st.begin(),st.end());
    return ans;
    }
};