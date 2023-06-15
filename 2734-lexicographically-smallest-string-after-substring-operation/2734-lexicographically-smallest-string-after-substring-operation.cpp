class Solution {
public:
    string smallestString(string s) {
        int i = 0; 
        while( i < s.length() && s[i] == 'a' ) i++;
        if( i >= s.length() ) {
            s[i-1] = 'z';
            return s;
        }
        while( i < s.length() && s[i] != 'a')
        {
            s[i]--;
            i++;
        }
           
        return s;
    }
};