class Solution {
public:
    int dp[101][101];
    bool isValid( int l, int h, vector<int> &n, int m )
    {
        int sum = 0; 
        for( int i = l; i <=h; ++i ) sum += n[i];
        
        return sum >= m;
    }
    bool help( int l, int h, vector<int> &n, int m )
    {
        if( l == h ) return true;
        if( !isValid(l,h,n,m) ) return false;
        if( dp[l][h] != -1 ) return dp[l][h];
        
        bool ans = false;
        for( int part = l; part< h; ++part )
        {
            bool left = help(l,part,n,m);
            bool right = help(part+1,h,n,m);
            if( left && right ) {ans = true; break;}
        }
        return dp[l][h] = ans;
    }
    bool canSplitArray(vector<int>& nums, int m) {
        if( nums.size() <= 2 ) return true;
        memset(dp,-1,sizeof(dp));
        return help(0,nums.size()-1,nums,m);
    }
};