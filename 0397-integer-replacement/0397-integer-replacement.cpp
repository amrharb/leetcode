class Solution {
public:
    #define ll long long
    int integerReplacement(ll n) {
        if(n==1)
            return 0;
        if(n&1)
            return 1+min(integerReplacement(n+1),integerReplacement(n-1));
        return 1+integerReplacement(n/2);
    }
};