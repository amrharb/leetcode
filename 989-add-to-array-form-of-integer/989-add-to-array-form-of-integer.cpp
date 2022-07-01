class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        reverse(num.begin(),num.end());
        int carry=k;
        for(auto&it:num){
            carry+=it;
            it=carry%10;
            carry/=10;
        }
        while(carry)num.push_back(carry%10),carry/=10;
        reverse(num.begin(),num.end());
        return num;
    }
};