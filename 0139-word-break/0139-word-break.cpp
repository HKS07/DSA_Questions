class Solution {
public:
    int dp[301];
    bool help( int pos, string s, set<string> &dict )
    {
        if( pos == s.length() ) return 1;
        if(dp[pos] != -1 ) return dp[pos];
        string word = "";
        
        for( int i = pos; i < s.length(); ++i )
        {
            word += s[i];
            if( dict.find(word) != dict.end() )
                if( help(i+1, s, dict) ) return dp[i+1] = 1;
        }
        return dp[pos] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> d(wordDict.begin(),wordDict.end());
        // for( auto i: d) cout<<i<<" ";
        memset(dp,-1,sizeof(dp));
        return help(0,s,d);
    }
};