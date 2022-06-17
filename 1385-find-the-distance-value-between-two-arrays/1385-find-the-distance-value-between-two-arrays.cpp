class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n=arr1.size(),m=arr2.size(),cnt=0;
        sort(arr2.begin(),arr2.end());
        for(int i=0;i<n;i++){
            int a=lower_bound(arr2.begin(),arr2.end(),arr1[i])-arr2.begin();
           if(a>=0&&a<m&&arr2[a]-arr1[i]<=d)continue;
            a=lower_bound(arr2.begin(),arr2.end(),arr1[i]-d)-arr2.begin();
            if(a>=0&&a<m&&arr2[a]-arr1[i]<=d)continue;
                cnt++;
        }
        return cnt;
    }
};