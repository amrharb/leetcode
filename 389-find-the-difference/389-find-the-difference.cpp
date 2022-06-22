class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum=0;
        for(auto&it:t)sum+=it;
        for(auto&it:s)sum-=it;
        return sum;
    }
};