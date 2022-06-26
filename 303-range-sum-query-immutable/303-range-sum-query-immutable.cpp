class NumArray {
public:
    vector<int>pref;
    NumArray(vector<int>& nums) {
        pref=vector<int>(nums.size());
        pref=nums;
        for(int i=1;i<nums.size();i++)pref[i]+=pref[i-1];
    }
    
    int sumRange(int left, int right) {
        return pref[right]-(left ? pref[left-1]:0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */