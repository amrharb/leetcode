#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
class Solution {
public:
    long long goodTriplets(vector<int>& a, vector<int>& b) {
        int n = a.size(), lessEleTillNow, moreEleTillNow, moreEleAfter;
        long long ans = 0;
        ordered_set s;
        vector<int> indexSortAccA(n) , bIndex(n);
        for(int i=0;i<n;i++) bIndex[b[i]] = i;
        for(int i=0;i<n;i++) indexSortAccA[i] = bIndex[a[i]];
        for(int i=0;i<n;i++){
            lessEleTillNow = s.order_of_key(indexSortAccA[i]);
            moreEleTillNow = i-lessEleTillNow;
            moreEleAfter = n-1-indexSortAccA[i]-moreEleTillNow;
            ans += (long long)lessEleTillNow*moreEleAfter;
            s.insert(indexSortAccA[i]);
        }
        return ans;
    }
};