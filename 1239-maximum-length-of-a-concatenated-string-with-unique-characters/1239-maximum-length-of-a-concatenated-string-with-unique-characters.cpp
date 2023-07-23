#include <algorithm>

class Solution {
public:
    int isGood( string s )
    {
         vector<int> alpha(26,0);
        
        for( int i = 0; i < s.length(); ++i  )
        {
            if( ++alpha[s[i]-'a'] > 1 ) return 0;
        }
        return s.length();
    }
    void help( int idx, vector<string>& arr, string s, int &ans )
    {
        if( idx < 0 )
        {
            if( ans < isGood(s) ) ans = s.length();
            return ;
        }
        
        help( idx - 1, arr, s, ans);
        help( idx - 1, arr, s + arr[idx], ans);
        
        
        
    }
    int maxLength(vector<string>& arr) {
        string a = "";
        int ans = 0;
         help( arr.size()-1, arr, a, ans);
        return ans;
    }
};