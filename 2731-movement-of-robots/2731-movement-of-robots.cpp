class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        //collision and no collision both will give same distance
        // because number of element going left and right after collision would be same(think)
        int mod = 1e9 + 7;
        
        // calculating final position
        for( int i = 0; i < nums.size(); ++i )
        {
            if( s[i] == 'L' ) nums[i] -= d;
            else nums[i] += d;
        }
        
        // calculating distance
        sort(nums.begin(),nums.end());
        long long sum = 0,sol=0;
        for( int i = 0; i < nums.size(); ++i )
        {
            sol = (sol + ((long long)nums[i]*i - sum)%mod)%mod;
            sum = (sum + nums[i])%mod;
        }
        return sol;
    }
};