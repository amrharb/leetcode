class Solution {
public:
    bool check(vector<int>v){
        for(auto&it:v)cout<<it<<" ";
        cout<<endl;
        for(int i=1;i<v.size();i++){
            if(v[i]<v[i-1])return 0;
        }
        return 1;
    }
    bool checkPossibility(vector<int>& v) {
        int n=v.size();
        bool flag=check(v);
        int tmp=v[0];
        v[0]=-1e5;
        flag|=check(v);
        v[0]=tmp;
        for(int i=1;i<n;i++){
            if(v[i]<v[i-1]){
                int temp=v[i];
                v[i]=v[i-1];
                flag|=check(v);
                v[i]=temp;
                if(i>1){
                    temp=v[i-1];
                    v[i-1]=v[i-2];
                    flag|=check(v);
                    v[i-1]=temp;
                }
                break;
            }
        }
        return flag;
    }
};