class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[&](vector<int>a,vector<int>b){
            if(a[1]==b[1])return a[0]<b[0];
            return a[1]>b[1];
        });
        int sum=0;
        for(int i=0;i<boxTypes.size();i++){
            int choose=min(boxTypes[i][0],truckSize);
            truckSize-=choose;
            sum+=choose*boxTypes[i][1];
        }
        return sum;
    }
};