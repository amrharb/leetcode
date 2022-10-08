class Solution
{
public:
    int threeSumClosest(vector<int>&v, int target)
    {
        int n=v.size(),mn=1e9,ans=0;
        bool flag=0;
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            int l=i+1,r=n-1;
            while(l<r){
                int sum=v[i]+v[l]+v[r];
                if(abs(sum-target)<mn){
                    mn=abs(target-sum);
                    ans=sum;
                }
                if(sum==target){
                    break;
                }
                else if(sum<target)l++;
                else r--;
            }
        }
        return ans;
    }
};
