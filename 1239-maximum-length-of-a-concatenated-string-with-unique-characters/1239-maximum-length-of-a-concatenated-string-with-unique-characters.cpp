class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n=arr.size();
        vector<int>v(n);
        for(int i=0;i<n;i++)
        {
            for(auto&it:arr[i])
                v[i]^=(1<<(it-'a'));
            bitset<26>bs(v[i]);
            if(bs.count()!=arr[i].size())
                v[i]=0;
        }
        int mx=0;
        for(int i=0;i<(1<<n);i++)
        {
            int sum=0,OR=0;
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))
                {
                    bitset<26>bs(v[j]);
                    sum+=bs.count();
                    OR|=v[j];
                }
            }
            bitset<26>bs(OR);
            if(sum==bs.count())
                mx=max(mx,sum);
        }
        return mx;
    }
};