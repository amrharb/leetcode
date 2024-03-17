class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>nw;
        auto st=intervals[0];
        int n=intervals.size();
        for(int i=1;i<n;i++)
        {
            if(st[1]>=intervals[i][0])
                st[1]=max(st[1],intervals[i][1]);
            else
            {
                nw.push_back(st);
                st=intervals[i];
            }
        }
        nw.push_back(st);
        return nw;
    }
};