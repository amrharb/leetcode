class Solution
{
public:
    int triangleNumber(vector<int>& v)
    {
        int n=v.size(),cnt=0;
        sort(v.begin(),v.end());
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int k=lower_bound(v.begin()+j+1,v.end(),v[i]+v[j])-v.begin();
                cnt+=k-j-1;
            }
        }
        return cnt;
    }
};
 