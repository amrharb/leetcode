class Solution {
public:
    int n,sf,sb,target;
    vector<int>v;
    int dp[8000][4];
    bool vis[8000][3];
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        n=2000+2*b;
        for(auto&it:forbidden)vis[it][0]=vis[it][1]=1;
        sf=a,sb=b,target=x;
        int steps=0;
        queue<pair<int,bool>>q;
        q.push({0,0});
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int i=q.front().first;
                bool can=!q.front().second;
                q.pop();
               if(i<0||i>n||vis[i][can])continue;
               if(i==x)return steps;
                vis[i][can]=1;
               if(can)q.push({i-sb,1});
               q.push({i+sf,0});
            }
            steps++;
        }
        return -1;
    }
};