class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        // ababab
        // 012345
        // 6-1 = 5
        
        for( int i = 0; i < n/2; ++i )
        {
            // creating substring
            string temp = s.substr(0, i+1 );
            string Final = temp;
            int repeat = (n-i-1)/(i+1);
            
            // for creating final string
            while( repeat )
            {
                Final += temp;
                repeat--;
            }
            if( Final == s ) return true;
        }
        
        return false;
    }
};