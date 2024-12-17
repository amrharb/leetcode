class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int>freq(26);
        for(auto it:s)freq[it-'a']++;
        string ans;
        while(accumulate(freq.begin(),freq.end(),0)){
            for(int i=25;i>=0;i--){
                if(freq[i]){
                    if(freq[i]>repeatLimit){
                        ans+=string(repeatLimit,char(i+'a'));
                        freq[i]-=repeatLimit;
                        int stop=-1;
                        for(int j=i-1;j>=0;j--){
                            if(freq[j]){
                                stop=j;
                                break;
                            }
                        }
                        if(~stop){
                            ans+=char(stop+'a');
                            freq[stop]--;
                        }else{
                            freq[i]=0;
                        }
                        break;
                    }else{
                        ans+=string(freq[i],char(i+'a'));
                        freq[i]=0;
                    }
                }
            }
        }
        return ans;
    }
};