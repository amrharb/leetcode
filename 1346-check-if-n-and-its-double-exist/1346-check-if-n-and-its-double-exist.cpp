class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n=arr.size(),cnt=0;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            if(arr[i]>=0){
            int l=i+1,r=n-1;
            while(l<=r){
                int mid=(l+r)/2;
                if(arr[mid]==arr[i]*2){
                    cnt++;
                    break;
                }
                else if(arr[mid]>arr[i]*2)r=mid-1;
                else l=mid+1;
            }}
            else{
                int l=0,r=i-1;
            while(l<=r){
                int mid=(l+r)/2;
                if(arr[mid]==arr[i]*2){
                    cnt++;
                    break;
                }
                else if(arr[mid]>arr[i]*2)r=mid-1;
                else l=mid+1;
            }
            }
        }
        return cnt;
    }
};