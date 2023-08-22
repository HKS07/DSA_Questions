class Solution {
public:
    int bs( vector<vector<int>>& o, int x )
    {
        int l = 0, h = o.size()-1, pos = -1;
        while( l <= h )
        {
            int mid = (l+h)/2;
            
            if( o[mid][0] > x )
            {
                pos = mid;
                h = mid -1;
            }
            else l = mid+1;
        }
        return pos;
    }
    int help( int idx, vector<vector<int>>& o, vector<int> &dp )
    {
        if( idx >= o.size() ) return 0;
        
        if( dp[idx] != -1 ) return dp[idx];
        
        int nextPos = bs(o, o[idx][1] );
        int take = 0, notTake = 0;
        
        take = o[idx][2] + help(nextPos, o, dp);
        notTake = help(idx+1,o,dp);
        
        return dp[idx] = max(take,notTake);
    }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(),offers.end());
        vector<int> dp(offers.size()+1,-1);
        return help(0,offers, dp);
    }
};