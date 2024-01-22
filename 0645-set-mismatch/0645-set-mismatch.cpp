class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int>freq;
        int temp=0,org=0;
        for(auto&it:nums)
        {
            if(++freq[it]==2)
                temp=it;
        }
        for(int i=1;i<=nums.size();i++)
            if(!freq[i]){
                org=i;
                break;
            }
        return vector<int>{temp,org};
    }
};