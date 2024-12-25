class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long  sum=accumulate(milestones.begin(),milestones.end(),0LL);
        int mx=*max_element(milestones.begin(),milestones.end());
        if(2*mx>sum)
            return (sum-mx)*2+1;
        return sum;
    }
};