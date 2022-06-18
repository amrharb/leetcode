class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& v) {
        sort(v.begin(),v.end());
        bool flag=1;
        int n=v.size();
        for(int i=2;i<n;i++){
            flag&=(v[i]-v[i-1]==v[1]-v[0]);
        }
        return flag;
    }
};