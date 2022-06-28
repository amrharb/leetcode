class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        vector<int>divisors;
        for(int i=1;i*i<=n;i++){
            if(n%i==0&&i<n){
                divisors.push_back(i);
                if(i*i!=n&&i!=1)divisors.push_back(n/i);
            }
        }
        for(auto&it:divisors){
            string last=s.substr(0,it);
            bool flag=1;
            for(int i=it;i<n;i+=it){
                if(s.substr(i,it)!=last){
                    flag=0;
                    break;
                }
            }
            if(flag)return cout<<it,1;
        }
        return 0;
    }
};