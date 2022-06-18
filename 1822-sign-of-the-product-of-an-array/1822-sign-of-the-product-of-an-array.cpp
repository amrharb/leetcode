class Solution {
public:
    int arraySign(vector<int>& v) {
        int n=v.size(),res=1;
        for(int i=0;i<n;i++){
            if(!v[i]){
                res=0;
                break;
            }
            else if(v[i]<0){
                if(res==-1)res=1;
                else res=-1;
            }
        }
        return res;
    }
};