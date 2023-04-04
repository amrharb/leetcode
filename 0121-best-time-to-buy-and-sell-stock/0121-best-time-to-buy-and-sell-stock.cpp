class Solution {
public:
    int maxProfit(vector<int>& v) {
        int mn=v[0],ans=0;
        for(auto it:v){
            if(it-mn>ans)
                ans=it-mn;
            if(it<mn)
                mn=it;
        }
        return ans;
    }
};