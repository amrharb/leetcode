class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int l=0,r=0,n=nums.size();
        long long cnt=0;
        multiset<int>st;
        while(l<n){
            while(r<n&&(st.empty()||abs(nums[r]-*st.begin())<=2&&abs(nums[r]-*st.rbegin())<=2)){
                st.insert(nums[r]);
                r++;
            }
            cnt+=r-l;
            st.erase(st.find(nums[l++]));
        }
        return cnt;
    }
};