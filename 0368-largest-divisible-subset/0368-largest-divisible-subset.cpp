class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        sort( arr.begin(), arr.end());
        int n = arr.size();

        vector<int> dp(n,1);
        vector<int> path, hash(n);
        int lastIdx= 0, maxLen = 1;

        for( int i = 0; i < n; ++i )
        {
            hash[i] = i;
            for( int pre = 0; pre < i; ++pre )
            {
                if( arr[i] % arr[pre] == 0 && 1 + dp[pre] > dp[i] )
                {
                    dp[i] = 1 + dp[pre];
                    hash[i] = pre;
                }
            }
            if( maxLen < dp[i] )
            {
                maxLen = dp[i];
                lastIdx = i;
            }
        }

        while( hash[lastIdx] != lastIdx )
        {
            path.push_back(arr[lastIdx]);
            lastIdx = hash[lastIdx];
        }
        path.push_back(arr[lastIdx]);
        // reverse(begin(path),end(path));

        return path;
    }
};