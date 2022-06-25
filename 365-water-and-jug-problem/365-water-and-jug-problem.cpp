class Solution {
public:
     bool canMeasureWater(int j1, int j2, int targetCapacity) {
        unordered_map<int,int>m;
        queue<int>q;
        q.push(0);
        m[0]=1;
        while(q.size()){
            int x=q.front();
            q.pop();
            
        if(x==targetCapacity)  return true;
            
           if((x+j1)<=(j1+j2) && m.find(x+j1)==m.end()) q.push(x+j1),m[x+j1]=1;; 
            if((x+j2)<=(j1+j2) && m.find(x+j2)==m.end()) q.push(x+j2),m[x+j2]=1;
            if((x-j1)>=0 && m.find(x-j1)==m.end())  q.push(x-j1),m[x-j1]=1;
            if((x-j2)>=0 && m.find(x-j2)==m.end())  q.push(x-j2),m[x-j2]=1;
        }
        return false;
    }
};