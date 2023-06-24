class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        if( nums.size() == 1) return nums[0];
        int neg = 0,zeros = 0;
        for( auto i: nums ) {if(i<0) neg++;if(i==0) zeros++;}
        
        if( neg == 0 && zeros == nums.size() ) return 0;
        if( neg == 1 && zeros == nums.size()-1 ) return 0;
        if( neg%2==0 )
        {
            long long sol = 1;
            for( auto i: nums ) if( i != 0 ) sol *= i;
            return sol;
        }
        else 
        {
            long long sol = 1;
            int minNum = INT_MAX, idx;
            for( int i = 0; i < nums.size(); ++i )
            {
                if(  nums[i] < 0 && (-1*nums[i]) < minNum  )
                {
                    minNum = -1 * nums[i], idx = i;
                }
            }
            for( int i = 0; i < nums.size(); ++i )
            {
                if( i != idx && nums[i] != 0 ) sol *= nums[i];
            }
            return sol;
        }
    }
};