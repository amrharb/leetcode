class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        set<int>total,last;
        for(auto&it:arr)
        {
            set<int>cur;
            for(auto&el:last)
                cur.insert(el|it);
            cur.insert(it);
            last=cur;
            total.insert(last.begin(),last.end());
        }
        return total.size();
    }
};