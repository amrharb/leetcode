class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        int bit = 0;
        for (int i = 30; i >= 0; i--) {
            if (n & (1 << i)) {
                bit = i;
                break;
            }
        }
        return (1 << (bit + 1));
    }
};