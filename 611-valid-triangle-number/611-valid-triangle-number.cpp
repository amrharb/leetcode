class Solution
{
public:
    int triangleNumber(vector<int>& v)
    {
        int n=v.size(),cnt=0;
        sort(v.begin(),v.end());
        for(int i=0; i<n-2; i++)
        {
            int k=i+2;
            for(int j=i+1; j<n-1&&v[i]; j++)
            {
                while(k<v.size()&&v[i]+v[j]>v[k])k++;
                cnt+=k-j-1;
            }
        }
        return cnt;
    }
};
 