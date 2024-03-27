class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& v, int k) {
        int cnt=0,n=v.size();
        for(int i=0;i<n;i++)
        {
            int product=1;
            for(int j=i;j<n;j++)
            {
                product*=v[j];
                if(product>=k)break;
                cnt++;
            }
        }
        return cnt;
    }
};