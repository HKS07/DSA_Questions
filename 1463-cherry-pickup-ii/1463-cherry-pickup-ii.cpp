class Solution {
public:
    int helpPick( int i, int j1, int j2, vector<vector<int>>& g, vector<vector<vector<int>>> &dp)
    {
        int r= g.size(),c=g[0].size();
        if( j1 < 0 || j1 >= c || j2 < 0 || j2 >= c) return -1e8;
        if( i == r-1) 
        {
            if( j1 == j2 ) return g[i][j1];
            else return g[i][j1] + g[i][j2];    
        }
        if( dp[i][j1][j2] != -1 ) return dp[i][j1][j2];
        //explore all choices
        int maxi = -1e8;
        for( int d1 = -1; d1 <= +1; ++d1)
        {
            for( int d2 = -1; d2 <= +1; ++d2)
            {
                int val = 0;
                if(j1==j2)
                {
                    val = g[i][j1];
                }
                else
                {
                    val = g[i][j1]+g[i][j2];
                }
                val += helpPick(i+1,j1+d1,j2+d2,g,dp);
                maxi = max(maxi, val );
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int r= grid.size(),c=grid[0].size();
        // vector<vector<vector<int>>> dp(MAX_X, vector<vector<int>>(MAX_Y, vector<int>(MAX_Z, 0)));
        vector<vector<vector<int>>> dp(70, vector<vector<int>> (70 ,vector<int> (70,-1)));
        return helpPick(0,0,c-1,grid,dp);
    }
};