class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero=0,product=1;
        for(auto it:nums){
            if(it==0)
                zero++;
            else
                product*=it;
        }
        vector<int>ans;
        if(zero>1)return vector<int>(nums.size());
        for(auto it:nums){
            if(zero){
                if(!it)
                   ans.push_back(product);
                else
                    ans.push_back(0);
            }else{
                ans.push_back(product/it);
            }
        }
        return ans;
    }
};