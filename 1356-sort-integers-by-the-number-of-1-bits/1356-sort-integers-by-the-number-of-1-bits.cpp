class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            int bits_1 = bitset<14>(a).count();
            int bits_2 = bitset<14>(b).count();
            if (bits_1 != bits_2)
                return bits_1 < bits_2;
            return a < b;
        });
        return arr;
    }
};