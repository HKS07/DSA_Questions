class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int mod = 1e9 + 7;
        long long sol = 1, cnt = 0;
        bool flag = false;
        for( int i = 0; i < nums.size(); ++i )
        {
            if( nums[i] == 1 )
            {
                flag = 1;
                sol = (sol*(cnt+1))%mod;
                cnt = 0;
            }
            else if( nums[i] == 0 && flag == true )
                cnt++;
        }
        if(flag == false) return 0;
        
        return sol;
    }
};