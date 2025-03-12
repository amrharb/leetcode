class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int cnt=0;
        for(char i='a';i<='z';i++){
            int first=s.find(i);
            if(first==-1)continue;
            int last=s.rfind(i);
            for(char j='a';j<='z';j++){
                int idx=s.find(j,first+1);
                if(idx==-1||idx>=last)continue;
                cnt++;
            }
        }
        return cnt;
    }
};