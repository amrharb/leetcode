class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        vector<int>pref(n),suf(n),mx(n);
        for(int i=0;i<n;i++){
            pref[i]=nums[i]+(i ? pref[i-1]:0);
        }
        for(int i=n-1;i>=0;i--){
            suf[i]=nums[i]+(i!=n-1 ? suf[i+1]:0);
            mx[i]=max(suf[i],(i!=n-1 ? mx[i+1]:0));
        }
        int ans=-2e9,sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            ans=max(ans,sum);
            sum=max(sum,0);
        }
        for(int i=0;i<n-1;i++){
            ans=max(ans,pref[i]+mx[i+1]);
        }
        return ans;
    }
};