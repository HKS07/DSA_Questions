class Solution {
public:
    vector<vector<double>> dp;
    double help( int idx, int k, vector<int> &n )
    {
        if( idx >= n.size() ) return 0;
        if( !k ) return INT_MIN;
        if( dp[idx][k] != -1 ) return dp[idx][k];
        
        double maxAvg = DBL_MIN;
        double curSum = 0;
        for( int part = idx; part < n.size(); ++part )
        {
            curSum += n[part];
            maxAvg = max(maxAvg,  curSum/(part-idx+1) + help(part+1,k-1, n) );
        }
        return dp[idx][k] = maxAvg;
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
        dp = vector<vector<double>> (101,vector<double> (101,-1));
        return help(0,k,nums);
    }
};