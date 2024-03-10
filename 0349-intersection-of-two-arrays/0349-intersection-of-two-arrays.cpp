class Solution {
public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        int n=a.size(),m=b.size();
        sort(a.begin(),a.end());
        vector<int>c;
        for(int i=0;i<n;i++)
        {
            if(i&&a[i]==a[i-1])continue;
            for(int j=0;j<m;j++)
            {
                if(a[i]==b[j])
                {
                    c.push_back(a[i]);
                    break;
                }
            }
        }
        return c;
    }
};