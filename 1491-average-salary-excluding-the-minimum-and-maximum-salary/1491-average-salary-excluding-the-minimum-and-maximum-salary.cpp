class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(),salary.end());
        int sum=accumulate(salary.begin()+1,salary.end()-1,0);
        return sum*1.00000/(salary.size()-2);
    }
};