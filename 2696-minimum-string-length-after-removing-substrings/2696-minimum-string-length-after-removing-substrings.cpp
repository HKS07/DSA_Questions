class Solution {
public:
    int minLength(string s) {
        
        int left = 0, right = 1;
        
        while( right < s.length() )
        {
            //matched 
            if( s[left] == 'A' && s[right] == 'B' || s[left] == 'C' && s[right] == 'D')
            {
                s.erase(left,2);
                left-=1; right-=1;
                if( left < 0 ) left = 0, right = 1;
                
            }
            //not matched
            else
            {
                left += 1;
                right += 1;
            }
        }
        return s.length();
    }
};