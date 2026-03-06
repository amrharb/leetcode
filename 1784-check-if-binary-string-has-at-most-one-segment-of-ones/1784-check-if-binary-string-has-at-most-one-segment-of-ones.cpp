class Solution {
public:
    bool checkOnesSegment(string s) {
        int idx = s.find("01",1);
        return idx == -1;
    }
};