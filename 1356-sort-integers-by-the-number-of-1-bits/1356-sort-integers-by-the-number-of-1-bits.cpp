class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),[&](int a,int b){
            bitset<32>s(a),x(b);
            if(s.count()!=x.count())return s.count()<x.count();
            return a<b;
        });
        return arr;
    }
};