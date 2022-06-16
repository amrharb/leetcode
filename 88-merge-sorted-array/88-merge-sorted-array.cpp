class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0;
        vector<int>v(n+m);
        for(int k=0;k<n+m;k++){
            if(i<m&&j<n){
                if(nums1[i]<=nums2[j])v[k]=nums1[i++];
                else v[k]=nums2[j++];
            }
            else if(i<m)v[k]=nums1[i++];
            else v[k]=nums2[j++];
        }
        nums1=v;
    }
};