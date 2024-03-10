class Solution {
public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        int n=a.size(),m=b.size();
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        vector<int>c;
        for(int i=0;i<n;i++)
        {
            if(i&&a[i]==a[i-1])continue;
            int idx=lower_bound(b.begin(),b.end(),a[i])-b.begin();
            if(idx!=m&&a[i]==b[idx])
                c.push_back(a[i]);
        }
        return c;
    }
};