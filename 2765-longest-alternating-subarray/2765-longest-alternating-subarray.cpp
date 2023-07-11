class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int sol = 0; 
        
        for( int i = 0; i < nums.size()-1; ++i )
        {
            int d = 1, j;
            for(  j = i + 1; j < nums.size(); ++j )
            {
                if( nums[j] - nums[j-1] != d ) break;
                d = d==1?-1:1;
            }
            sol = max( sol, j-i);
        }
        return sol>1?sol:-1;
    }
};