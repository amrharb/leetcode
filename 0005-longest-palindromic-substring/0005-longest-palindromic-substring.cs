public class Solution {
    public string LongestPalindrome(string s) {
        int max = -1;
        var res= "" ;   
        for(int i =0 ; i < s.Length; i++)
        {
            for(int j = i ; j < s.Length; j++)
            {
                if(Ispalindromic(s,i,j))
                {
                    if(max < j - i + 1)
                    {
                        max = j - i + 1;
                        res = s.Substring(i, j-i+1); 
                    }
                }
            }
        }
        return res;
    }

    bool Ispalindromic(string s , int i ,int j)
    {
        if( i >= j )
        {
            return true;
        }

        if(s[i] != s[j]) return false;

        return Ispalindromic(s, i+1, j-1);
    }

}
