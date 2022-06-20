class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n=arr.size(),tot=0;
        for(int i=0;i<n;i++){
            int numOfTimes=(i+1)*(n-i);
            tot+=arr[i]*((numOfTimes+1)/2);
        }
        return tot;
    }
};