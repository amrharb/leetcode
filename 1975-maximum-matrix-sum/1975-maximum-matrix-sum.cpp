class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans=0;
        int min_val=INT_MAX;
        bool odd_neg=0;
        for(auto row:matrix){
            for(auto element:row){
                ans+=abs(element);
                if(element<0)
                    odd_neg^=1;
                min_val=min(min_val,abs(element));
            }
        }
        ans-=2*odd_neg*min_val;
        return ans;
    }
};