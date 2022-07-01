class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        reverse(num.begin(),num.end());
        int carry=k;
        for(auto&it:num){
            it+=carry;
            carry=it/10;
            it%=10;
        }
        while(carry)num.push_back(carry%10),carry/=10;
        reverse(num.begin(),num.end());
        return num;
    }
};