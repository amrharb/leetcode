class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int cnt=1,l=points[0][0],r=points[0][1],n=points.size();
        for(int i=1;i<n;i++){
            if(points[i][0]>r||points[i][1]<l)cnt++,l=points[i][0],r=points[i][1];
            else l=max(l,points[i][0]),r=min(r,points[i][1]);
        }
        return cnt;
    }
};