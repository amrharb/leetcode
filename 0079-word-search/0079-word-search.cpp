int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
bool valid(int i,int j,vector<vector<char>>&board)
{
    return i>=0&&j>=0&&i<board.size()&&j<board[0].size();
}
class Solution {
public:
    bool exist(vector<vector<char>>& board, string &word,int i=0,int j=0,int cur=0,bool st=0) {
        if(cur==word.size())
            return true;
        bool ret=false;
        if(!st)
        {
            for(int x=0;x<board.size()&&!ret;x++)
            {
                for(int y=0;y<board[0].size()&&!ret;y++)
                {
                    if(board[x][y]==word[0])
                    {
                        char temp='#';
                        swap(board[x][y],temp);
                        ret|=exist(board,word,x,y,1,1);
                        swap(board[x][y],temp);
                    }
                }
            }
            return ret;
        }
        for(int k=0;k<4&&!ret;k++)
        {
            int x=i+dx[k],y=j+dy[k];
            if(valid(x,y,board)&&board[x][y]==word[cur])
            {
                char temp='#';
                swap(board[x][y],temp);
                ret|=exist(board,word,x,y,cur+1,1);
                swap(board[x][y],temp);
            }
        }
        return ret;
    }
};