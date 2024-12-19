class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        int chunks=0,sum=0;
        for(int i=0;i<n;i++){
            sum+=i;
            sum-=arr[i];
            if(!sum)
                chunks++;
        }
        return chunks;
    }
};