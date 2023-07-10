class Solution {
public:
    int dp[100005][3];
    int help( int idx, int prevNum, int prevArr, vector<int>& nums1, vector<int>& nums2)
    {
        if( idx >= nums1.size()) return 0;
        if(dp[idx][prevArr] != -1 ) return dp[idx][prevArr];
        int sol = 0;
        if( prevArr == 0 )
        {
            int nTake = 0 + help(idx+1, prevNum, 0, nums1, nums2 );
            int take1 = 1 + help(idx+1, nums1[idx], 1, nums1, nums2 );
            int take2 = 1 + help(idx+1, nums2[idx], 2, nums1, nums2 );
            sol = max({nTake, take1, take2});
        }
        else if( prevArr == 1 )
        {
            if( prevNum <= nums1[idx] ) sol = max(sol, 1 + help(idx+1, nums1[idx], 1, nums1, nums2 ));
            if( prevNum <= nums2[idx] ) sol = max(sol, 1 + help(idx+1, nums2[idx], 2, nums1, nums2 ));
        }
        else
        {
            if( prevNum <= nums1[idx] ) sol = max(sol, 1 + help(idx+1, nums1[idx], 1, nums1, nums2 ));
            if( prevNum <= nums2[idx] ) sol = max(sol, 1 + help(idx+1, nums2[idx], 2, nums1, nums2 ));
        }
        return dp[idx][prevArr] = sol;
    }
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        return help(0,-1,0,nums1,nums2);
    }
};