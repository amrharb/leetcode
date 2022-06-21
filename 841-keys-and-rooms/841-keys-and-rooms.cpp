class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>vis(n,0);
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            auto cur=q.front();q.pop();
            vis[cur]=1;
            for(auto&it:rooms[cur]){
                if(!vis[it])q.push(it);
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i])return 0;
        }
        return 1;
    }
};