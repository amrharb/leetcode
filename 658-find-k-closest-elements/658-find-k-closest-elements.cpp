class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int index=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        int l=index-1,r=index;
        vector<int>ans;
        while(k--){
            if(l==-1)ans.push_back(arr[r++]);
            else if(r==arr.size())ans.push_back(arr[l--]);
            else{
                if(abs(arr[l]-x)<=abs(arr[r]-x))ans.push_back(arr[l--]);
                else ans.push_back(arr[r++]);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};