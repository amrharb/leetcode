class Solution {
public:
    bool isMonotonic(vector<int>& v) {
        bool flag=1;
        int n=v.size();
        for(int i=1;i<n;i++){
            flag&=(v[i]<=v[i-1]);
        }
        if(flag)return true;
        flag=1;
        for(int i=1;i<n;i++){
            flag&=(v[i]>=v[i-1]);
        }
        return flag;
    }
};