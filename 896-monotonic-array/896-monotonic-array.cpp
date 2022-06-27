class Solution {
public:
    bool isMonotonic(vector<int>& v) {
        bool flag1=1,flag2=1;
        int n=v.size();
        for(int i=1;i<n;i++){
            flag1&=(v[i]<=v[i-1]);
            flag2&=(v[i]>=v[i-1]);
        }
        return flag1||flag2;
    }
};