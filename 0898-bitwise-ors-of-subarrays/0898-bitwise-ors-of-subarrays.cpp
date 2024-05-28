class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int>total,last,cur;
        for(auto&it:arr)
        {
           cur={it};
            for(auto&el:last)
                cur.insert(el|it);
            last=cur;
            total.insert(last.begin(),last.end());
        }
        return total.size();
    }
};