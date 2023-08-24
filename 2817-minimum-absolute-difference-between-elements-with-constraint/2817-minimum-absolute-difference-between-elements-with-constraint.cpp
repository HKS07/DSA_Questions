class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        if( x == 0 ) return 0;
        int mini = INT_MAX;
        set<int> s;
        
        for( int i = x; i < nums.size(); ++i )
        {
            s.insert(nums[i-x]);
            
            auto small = s.lower_bound(nums[i]);
            if( small == s.end() )
            {
                small--;
            }
            int num = *small;
            mini = min( mini, abs(nums[i] - num));
            
            if( small == s.begin()) continue;
            small--;
            
            num = *small;
            mini = min( mini, abs(nums[i] - num));
        }
        return mini;
    }
};