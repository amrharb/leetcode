class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        multiset<int,greater<int>>st;
        for(auto&it:stones)st.insert(it);
        while(st.size()>1){
            auto a=*st.begin();st.erase(st.begin());
            auto b=*st.begin();st.erase(st.begin());
            if(a-b)st.insert(a-b);
        }
        if(st.size())return *st.begin();
        return 0;
    }
};