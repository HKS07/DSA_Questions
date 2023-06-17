class Solution {
public:
    int helpClimb(int curStep, int n, vector<int> &dp )
    {
        //base case
        if( curStep == n ) return 1;
        if( curStep >n ) return 0;
        if( dp[curStep] != -1 ) return dp[curStep];
        //possibilities
        int oneStep = helpClimb( curStep+1, n, dp);
        int twoStep = helpClimb( curStep+2, n, dp);
        //
        return dp[curStep] = oneStep + twoStep;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return helpClimb(0,n,dp);
    }
};