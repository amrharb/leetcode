class Solution {
public:
    int convertTime(string current, string correct) {
        int cur_minutes=stoi(current.substr(0,2))*60+stoi(current.substr(3));
        int cor_minutes=stoi(correct.substr(0,2))*60+stoi(correct.substr(3));
        if(cur_minutes>cor_minutes)cor_minutes+=24*60;
        int remaining_time=cor_minutes-cur_minutes;
        int op=remaining_time/60;
        remaining_time%=60;
        op+=remaining_time/15;
        remaining_time%=15;
        op+=remaining_time/5;
        remaining_time%=5;
        op+=remaining_time;
        return op;
    }
};