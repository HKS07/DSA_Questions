class Solution {
public:
    bool comp( string a, string b )
    {
        int al = a.length(), bl = b.length(), i = 0, j = 0, flag = 1;
    if( abs(al-bl) != 1 ) return false;
        if( al < bl ) {swap(a,b);swap(al,bl);}
        while( i < al && j < bl )
        {
            if( a[i] == b[j] ) ++i, ++j;
            else if( flag == 1)
            {
                ++i;
                flag = 0;
            }
            else{ return false;}
        }
        return true;
    }
    static bool com( string a, string b )
    {
        if( a.length() < b.length() ) return true;
        else return false;
    }
    int longestStrChain(vector<string>& arr) {
         int n = arr.size();
        vector<int> dp(n,1);
        sort(arr.begin(),arr.end(),com);
        int maxLen = 1;

        for( int i = 1; i < n; ++i )
        {
            for( int pre = 0; pre < i; ++pre )
            {
                if( comp(arr[i],arr[pre]) && 1 + dp[pre] > dp[i] )
                {
                    dp[i] = dp[pre] + 1;
                }
            }
            if( maxLen < dp[i] )
            {
                maxLen = dp[i];
            }
        }
        return maxLen;
    }
};