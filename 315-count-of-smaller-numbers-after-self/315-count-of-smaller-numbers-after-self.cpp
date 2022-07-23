#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;
class Solution {
public:
    vector<int> countSmaller(vector<int>& v) {
        ordered_set st;
        int n=v.size();
        vector<int>ans(n);
        for(int i=n-1;~i;i--){
            ans[i]=st.order_of_key({v[i],-1});
            st.insert({v[i],n-i});
        }
        return ans;
    }
};