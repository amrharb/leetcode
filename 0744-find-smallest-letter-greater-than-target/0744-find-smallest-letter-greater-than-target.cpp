class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        auto ch = upper_bound(letters.begin(), letters.end(), target) -
                  letters.begin();
        return letters[ch % n];
    }
};