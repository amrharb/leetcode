class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int>temp=nums;
        sort(temp.begin(),temp.end());
        int n=nums.size();
        vector<int>len(temp.size()),nxt(temp.size(),n),ans;
        int mx=1;
        for(int i=n-1;i>=0;i--)
        {
            len[i]=1;
            for(int j=i+1;j<n;j++)
            {
                if(temp[j]%temp[i]==0)
                {
                    if(len[j]+1>len[i])
                        len[i]=len[j]+1,nxt[i]=j,mx=max(mx,len[i]);
                }
            }
        }
        int st=max_element(len.begin(),len.end())-len.begin();
        while(st!=n)
            ans.push_back(temp[st]),st=nxt[st];
        return ans;
    }
};