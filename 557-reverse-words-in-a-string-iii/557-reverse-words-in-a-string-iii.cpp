class Solution {
public:
    string reverseWords(string s) {
        string x,k;
        istringstream iss(s);
        while(iss>>x){
            reverse(x.begin(),x.end());
            k+=x;
            k+=' ';
        }
        k.pop_back();
        return k;
    }
};