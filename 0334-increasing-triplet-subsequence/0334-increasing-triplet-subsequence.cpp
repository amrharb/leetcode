class Solution {
public:
    bool increasingTriplet(vector<int>& v) {
        int n=v.size();
        vector<int>arr;
        for(int i=0;i<n;i++){
            int k=lower_bound(arr.begin(),arr.end(),v[i])-arr.begin();
            if(k==arr.size())arr.push_back(v[i]);
            else arr[k]=v[i];
        }
        return arr.size()>=3;
    }
};