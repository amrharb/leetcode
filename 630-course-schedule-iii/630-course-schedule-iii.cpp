class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),[](vector<int>a,vector<int>b){
            return a[1]<b[1];
        });
        int time=0,cnt=0,n=courses.size();
        for(int i=0;i<n;i++){
            if(time+courses[i][0]<=courses[i][1]){
                time+=courses[i][0];
                courses[cnt++]=courses[i];
            }
            else{
                int take=i;
                for(int j=0;j<cnt;j++){
                    if(courses[j][0]>courses[take][0]){
                        take=j;
                    }
                }
                if(courses[take][0]>courses[i][0]){
                    time+=courses[i][0]-courses[take][0];
                    courses[take]=courses[i];
                }
            }
        }
        return cnt;
    }
};