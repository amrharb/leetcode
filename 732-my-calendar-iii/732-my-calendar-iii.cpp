class MyCalendarThree {
public:
    map<int,int>mp;
    MyCalendarThree() {
        mp.clear();
    }
    
    int book(int start, int end) {
        int cur=0,res=0;
        mp[start]++;
        mp[end]--;
        for(auto&it:mp){
            cur+=it.second;
            res=max(res,cur);
        }
        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */