class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        int n=v.size();
        set<vector<int>>ans;
        map<int,int>mp;
        for(int i=0;i<n;i++)mp[v[i]]++;
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            if(i&&v[i]==v[i-1])continue;
            for(int j=i+1;j<n;j++){
                if(j>i+1&&v[j]==v[j-1])continue;
                if(mp.find(-(v[i]+v[j]))==mp.end())
                    continue;
                int target=-(v[i]+v[j]),freq=mp[target];
                if(v[i]==target)freq--;
                if(v[j]==target)freq--;
                if(!freq)continue;
                vector<int>add={v[i],v[j],target};
                sort(add.begin(),add.end());
                ans.insert(add);
            }
        }
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};