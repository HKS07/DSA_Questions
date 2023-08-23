class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0, j = 0, s1 = str1.length(), s2 = str2.length();
        
        while( i < s1 && j < s2 )
        {
            if( str1[i] == str2[j] || str1[i] + 1 == str2[j] || str1[i] == 'z' && str2[j] =='a' )
            {
                ++i;++j;
            }
            else ++i;
        }
        
        return j==s2;
    }
};