class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        vector<int>pos(n);
        for(int i=0;i<n;i++)
            pos[arr[i]]=i;
        int chunks=0,mx=0;
        for(int i=0;i<n;i++){
            mx=max(mx,i);
            mx=max(mx,pos[i]);
            if(mx==i)chunks++;
        }
        return chunks;
    }
};