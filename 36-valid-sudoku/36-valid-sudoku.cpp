class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool flag=0;
        map<int,map<char,int>>mp,mk;
        map<pair<int,int>,map<char,int>>b;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    mp[i][board[i][j]]++;
                    mk[j][board[i][j]]++;
                    b[{i/3,j/3}][board[i][j]]++;
                    flag|=(mk[j][board[i][j]]==2||mp[i][board[i][j]]==2||b[{i/3,j/3}][board[i][j]]==2);
                }
            }
        }
        return !flag;
    }
};