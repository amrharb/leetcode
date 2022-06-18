class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto ch=upper_bound(letters.begin(),letters.end(),target);
        if(ch==letters.end()){
            return letters[0];
        }
        return *ch;
    }
};