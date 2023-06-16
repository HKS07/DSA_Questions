class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int len = 1, l = 0, r = 1, lastIdx = 0;
        
        while( l < r && r < s.length() )
        {
            if( s[r] == s[r-1] )
            {
                if( lastIdx )
                {
                    l = lastIdx;
                }
                lastIdx = r;
            }
            len = max( len, r - l + 1);
            r++;
        }
        return len;
    }
};