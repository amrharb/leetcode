class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n=tasks.size();
        bool flag=0;
        int ans=0,cnt=1;
        sort(tasks.begin(),tasks.end());
        for(int i=1;i<n;i++){
            if(tasks[i]==tasks[i-1])cnt++;
            else flag|=(cnt==1),ans+=(cnt+2)/3,cnt=1;
        }
        flag|=(cnt==1);
        ans+=(cnt+2)/3;
        if(flag)return -1;
        return ans;
    }
};