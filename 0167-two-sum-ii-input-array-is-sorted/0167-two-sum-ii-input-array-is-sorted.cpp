class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        for(int i=0;i<n;i++){
            int rem=target-numbers[i];
            int idx=lower_bound(numbers.begin()+i+1,numbers.end(),rem)-numbers.begin();
            if(idx<n&&numbers[idx]==rem)return {i+1,idx+1};
        }
        return {1,2};
    }
};