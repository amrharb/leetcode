class Solution {
public:
    set<int>ans;
    int m,l;
    void solve(int i,int cur,long long last){
        if(i==m){ans.insert(last);return;}
        if(cur-l>=0)solve(i+1,cur-l,last*10+cur-l);
        if(cur+l<10)solve(i+1,cur+l,last*10+cur+l);
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        m=n,l=k;
        for(int i=1;i<10;i++)solve(1,i,i);
        return vector<int>(ans.begin(),ans.end());
    }
};