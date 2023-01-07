class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int sum=0,start=0;
        for(int i=0;i<n;i++){
            sum+=gas[i]-cost[i];
            if(sum<0){
                sum=0;
                start=i+1;
            }
        }
        return (start<n&&accumulate(gas.begin(),gas.end(),0)>=accumulate(cost.begin(),cost.end(),0) ? start:-1);
    }
};