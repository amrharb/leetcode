class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0;
        vector<int>v(n+m);
        for(int i=0;i<m;i++){
            v[i]=nums1[i];
        }
        for(int i=m;i<n+m;i++){
            v[i]=nums2[i-m];
        }
        sort(v.begin(),v.end());
        nums1=v;
    }
};