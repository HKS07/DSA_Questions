class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end());
        int sol = 0;
        int start = nums[0][0], end = nums[0][1], flag = 0;
        
        for( int i = 1; i < nums.size(); ++i )
        {
            if( end >= nums[i][0] )
            {
                end = max(end, nums[i][1]);
            }
            else
            {
                sol += end-start+1;
                flag = 1;
                start = nums[i][0]; end = nums[i][1];
            }
        }
        sol += end-start +1;
        return sol;
    }
};