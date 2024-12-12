class Solution {
public:
    #define ll long long
    int integerReplacement(ll n) {
        int cnt=0;
        while(n!=1){
            if(n%2==0)n/=2;
            else{
                if((n/2)%2==0||n==3)n--;
                else if((n/2+1)%2==0)n++;
                else n--;
            }
            cnt++;
            cout<<n<<' ';
        }
        return cnt;
    }
};