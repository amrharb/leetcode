class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq;
        for(auto&it:gifts){
            pq.push(it);
        }
        while(k--&&pq.top()>1){
            int mx=pq.top();
            pq.pop();
            pq.push((int)sqrt(mx));
        }
        long long ans=0;
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};