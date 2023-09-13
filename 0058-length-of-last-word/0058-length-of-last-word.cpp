class Solution {
public:
    int lengthOfLastWord(string s) {
        if( s.length() == 1 ) s[0] != ' ';
        int n = s.length()-1, end = n, start;
        while( end >= 0 &&  s[end] == ' ') end--;
        // if( end == 0 ) return 0;
        start = end;
        while( start - 1 >= 0 && s[start -1 ] != ' ' ) --start;
        
        return end - start + 1;
    }
};