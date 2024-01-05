class Solution {
public:
    int minOperations(vector<int>& nums) {
        int operations=0;
        map<int,int>freq;
        for(auto&it:nums)
        {
            freq[it]++;
        }
        for(auto&[a,b]:freq)
        {
            if(b==1)
                return -1;
            operations+=b/3+!!(b%3);
        }
        return operations;
    }
};