class Solution {
public:
    int minMaxDifference(int num) {
        string mx_num = to_string(num), mn_num = to_string(num);
        string str_num = to_string(num);
        for (char d : str_num) {
            if (d != '9') {
                for (char& D : mx_num) {
                    if (D == d)
                        D = '9';
                }
                break;
            }
        }
        for (char d : str_num) {
            if (d != '0') {
                for (char& D : mn_num) {
                    if (D == d)
                        D = '0';
                }
                break;
            }
        }
        return stoi(mx_num) - stoi(mn_num);
    }
};