class Solution {
private:
    bool helper(vector<double>& nums) {
        int n = nums.size();
        if (n == 1)
            return abs(nums[0] - 24.0) < 1e-6;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double a = nums[i];
                double b = nums[j];
                vector<double> op = calc(a, b);

                vector<double> next;
                for (int k = 0; k < n; k++) {
                    if (k != i && k != j)
                        next.push_back(nums[k]);
                }

                for (double o : op) {
                    next.push_back(o);
                    if (helper(next))
                        return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }

    vector<double> calc(double a, double b) {
        vector<double> v;
        v.push_back(a + b);
        v.push_back(a - b);
        v.push_back(b - a);
        v.push_back(a * b);
        if (fabs(b) > 1e-6)
            v.push_back(a / b);
        if (fabs(a) > 1e-6)
            v.push_back(b / a);
        return v;
    }

public:
    bool judgePoint24(vector<int>& cards) {
        int sum = 0;
        vector<double> ans(4);
        for (int i = 0; i < 4; i++) {
            sum += cards[i];
            ans[i] = cards[i];
        }
        if (sum < 9)
            return false;
        if (sum == 24)
            return true;
        vector<double> nums(4);
        for (int i = 0; i < 4; i++)
            nums[i] = cards[i];
        return helper(nums);
    }
};