class Solution {
public:
    bool isGood(set<char> &s)
    {
        for( auto i: s )
        {
            if( islower(i) && s.find(i-32) == s.end() ) return false;
            if( isupper(i) && s.find(i+32) == s.end() ) return false;
        }
        return true;
    }
    string longestNiceSubstring(string s) {
        string sol = "";
        int len = 0;
        
        for( int i = 0; i < s.length()-1; ++i )
        {
            set<char> st;
            st.insert(s[i]);
            for( int j = i + 1; j < s.length(); ++j )
            {
                st.insert(s[j]);
                if( isGood(st) )
                {
                    cout<<s.substr(i,j-i+1)<<" ";
                    if( len < j-i+1 ) 
                    {
                        sol = s.substr(i,j-i+1);
                        len = j-i+1;
                    }
                }
            }
        }
        return sol;
    }
};