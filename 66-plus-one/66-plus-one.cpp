class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        int carry=1;
        for(auto&it:digits){
            it+=carry;
            carry=it/10;
            it=it%10;
        }
        if(carry)digits.push_back(carry);
        reverse(digits.begin(),digits.end());
        return digits;
    }
};