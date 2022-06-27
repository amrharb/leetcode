class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int n=target.size(),steps=0;
        queue<string>q;
        map<string,int>vis;
        for(auto it:deadends)vis[it]=1;
        q.push(string(n,'0'));
        if(vis[q.front()])return -1;
        vis[q.front()]=1;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto cur=q.front();q.pop();
                if(cur==target)return steps;
                for(int i=0;i<n;i++){
                    string nw=cur;
                    nw[i]=(cur[i]-'0'+1)%10+'0';
                    if(vis.find(nw)==vis.end())q.push(nw),vis[nw]=1;
                    nw=cur;
                    nw[i]=(cur[i]-'0'-1+10)%10+'0';
                    if(vis.find(nw)==vis.end())q.push(nw),vis[nw]=1;
                }
            }
            steps++;
        }
        return -1;
    }
};