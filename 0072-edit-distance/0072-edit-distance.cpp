class Solution {
public:
    int help( string w1, string w2, int i, int j,  vector<vector<int>> &dp)
    {
        if( j < 0 )
        {
            return i + 1;
        }
        if( i < 0 ) 
        {
            return j + 1;
        }
        if( dp[i][j] != -1 ) return dp[i][j];
        if( w1[i] == w2[j] )
        {
            return dp[i][j] = 0 + help( w1, w2, i-1,j-1,dp);
        }
        else
        {
            int a =  1 + help( w1, w2, i - 1,j -1,dp);//replace
            int b =  1 + help( w1, w2, i -1, j,dp);//delete
            int c =  1 + help( w1, w2, i,j-1,dp );//insert
            return dp[i][j] = min(a,min(b,c));
        }
    }
    int minDistance(string word1, string word2) {
        int w1 = word1.length(), w2 = word2.length();
        vector<vector<int>> dp(w1, vector<int> (w2,-1));
        return help(word1, word2, w1-1,w2-1,dp);
        
    }
};