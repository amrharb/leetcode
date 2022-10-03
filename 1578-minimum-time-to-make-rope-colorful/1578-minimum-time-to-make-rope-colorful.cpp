class Solution {
public:
    int minCost(string s, vector<int>& neededTime) {
        int ans=0,mx=neededTime[0],temp=neededTime[0],cnt=1;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
                temp+=neededTime[i];
                mx=max(mx,neededTime[i]);
                cnt++;
            }
            else{
                ans+=(cnt>1)*(temp-mx);
                mx=neededTime[i];
                temp=neededTime[i];
                cnt=1;
            }
        }
        ans+=(cnt>1)*(temp-mx);
        return ans;
    }
};