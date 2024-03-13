class Solution {
public:
    int pivotInteger(int n) {
        int x=sqrt(n*(n+1)/2);
        return (x*x==(n*(n+1)/2) ? x:-1);
    }
};