class Solution {
public:
    int ladderLength(string start, string last, vector<string>& words) {
        int n=start.size();
        map<string,vector<string>>adj;
        for(auto &it:words){
            for(auto&el:words){
                int cnt=0;
                for(int k=0;k<n;k++){
                    cnt+=(it[k]!=el[k]);
                }
                if(cnt==1){
                    adj[it].push_back(el);
                }
            }
        }
        for(auto&it:words){
                int cnt=0;
                for(int k=0;k<n;k++){
                    cnt+=(start[k]!=it[k]);
                }
                if(cnt==1){
                    adj[start].push_back(it);
                }
            }
        queue<string>q;
        map<string,bool>mp;
        q.push(start);
        mp[start]=1;
        int steps=1;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto p=q.front();q.pop();
                for(auto&it:adj[p]){
                    if(it==last)return steps+1;
                    if(mp[it])continue;
                    mp[it]=1;
                    q.push(it);
                }
            }
            steps++;
        }
        return 0;
    }
};