class Solution {
public:
    bool check(vector<int>& ranks, int cars, long long time) {
        long long sum = 0;
        for (auto rank : ranks) {
            sum += (long long)sqrtl(time * 1.0 / rank);
        }
        return sum >= cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 0, r = 1e18;
        while (l <= r) {
            long long mid = (l + r) / 2;
            if (check(ranks, cars, mid))
                r = mid - 1;
            else
                l = mid + 1;
        }
        return r + 1;
    }
};