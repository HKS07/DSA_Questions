class Solution {
public:
    int lenHelp( int idx, int prevIdx, vector<int> &nums, int n, vector<vector<int> > &dp )
    {
        if( idx == n ) return 0;
        
        if( dp[idx][prevIdx + 1] != -1 ) return dp[idx][prevIdx+1];
        
        int len = lenHelp( idx +1 , prevIdx, nums, n, dp);
        
        if( prevIdx == -1 || nums[idx] > nums[prevIdx] )
            len = max( len, 1 + lenHelp( idx + 1, idx, nums, n, dp));
            
        return dp[idx][prevIdx+1] = len;
    }
    int lengthOfLIS(vector<int>& arr) {
//         vector<vector<int> > dp( nums.size(), vector<int>( nums.size() + 1, -1 ));
        
//         return lenHelp( 0, -1, nums, nums.size(), dp );
        int n = arr.size();
        // vector<vector<int>> dp(n+1, vector<int> (n+1,0));
        vector<int> next(n+1,0), cur(n+1,0);

        for( int idx = n-1; idx >= 0; --idx )
        {
            for( int preIdx = idx-1; preIdx >=-1 ; --preIdx )
            {
                int len = 0 + next[preIdx+1];

                if( preIdx == -1 || arr[idx] > arr[preIdx] )
                {
                    len = max( len , 1 + next[idx+1]);
                }
                cur[preIdx+1] = len;
            }
            next = cur;
        }
        return cur[0];
        
    }
};