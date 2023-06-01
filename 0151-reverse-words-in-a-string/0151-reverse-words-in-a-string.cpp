class Solution {
public:
    string reverseWords(string s) {
        //reach till first letter set start
        //move till space is encountered and set end = cur - 1
        //put this wored reverse in other string
        
        s+=" ";
        string sol = "";
        int start = -1,end = -1;
        
        for( int i = 0; i < s.length(); ++i )
        {
            // string a = s[i];
            if(  s[i] != ' ' && start == -1 )
            {
                start = i;
            }
            else if( s[i] != ' ')
            {
                continue;
            }
            else if( s[i] == ' ' && start != -1 )
            {
                end = i-1;
                string temp = s.substr( start, end - start + 1 );
                temp += " ";
                sol.insert(0, temp );
                start = -1;
            }
        }
        
        
        return sol.substr(0,sol.length()-1);
    }
};