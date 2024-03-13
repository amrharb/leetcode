class Solution {
public:
    int sum(int n)
    {
        return n*(n+1)/2;
    }
    int pivotInteger(int n) {
        int x=sqrt(n*(n+1)/2);
        return (sum(x)==sum(n)-sum(x-1) ? x:-1);
    }
};