class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sz=flowerbed.size();
        for(int i=0;i<sz;i++){
            if((!i||!flowerbed[i-1])&&(i==sz-1||!flowerbed[i+1]))
                n-=!flowerbed[i],flowerbed[i]=1;
            else if(flowerbed[i])
                return 0;
        }
        return (n<=0);
    }
};