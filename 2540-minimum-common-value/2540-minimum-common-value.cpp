class Solution {
public:
    int getCommon(vector<int>& a, vector<int>& b) {
        sort(a.rbegin(),a.rend());
        sort(b.rbegin(),b.rend());
        int i=a.size()-1,j=b.size()-1;
        while(i>=0&&j>=0)
        {
            if(a[i]==b[j])
                return a[i];
            if(a[i]>b[j])
                j--;
            else
                i--;
        }
        return -1;
    }
};