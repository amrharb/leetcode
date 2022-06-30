class Solution {
public:
    string getHint(string secret, string guess) {
        int n=secret.size(),cnt=0,cnt2=0;
        map<int,int>mp,mk;
        for(int i=0;i<n;i++){
            if(guess[i]==secret[i])cnt++;
            else mp[guess[i]]++,mk[secret[i]]++;
        }
        for(auto&it:mp){
            cnt2+=min(it.second,mk[it.first]);
        }
        return to_string(cnt)+'A'+to_string(cnt2)+'B';
    }
};