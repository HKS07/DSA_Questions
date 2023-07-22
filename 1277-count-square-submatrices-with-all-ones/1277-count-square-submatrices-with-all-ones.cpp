class Solution {
public:
    int countSquares(vector<vector<int>>& m) {
     int r =  m.size(), c = m[0].size();
     vector<vector<int>> dp(r, vector<int> (c,0));
        
     for (int j = 0; j < c; j++) dp[0][j] = m[0][j];
     for (int i = 0; i < r; i++) dp[i][0] = m[i][0];
        
     for( int i = 1; i < r; ++i )
     {
         for( int j = 1; j < c; ++j )
         {
             if( m[i][j] == 0 ) dp[i][j] = 0;
             else dp[i][j] = 1 + min({dp[i][j-1],dp[i-1][j-1],dp[i-1][j]});
         }
     }
     int sum = 0;
        for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            sum += dp[i][j];
        }
    }
     return sum;
    }
};