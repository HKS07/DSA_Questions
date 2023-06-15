class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
         // if( nums.size() == 1 ) return -1;
        int minn = INT_MAX, maxx = INT_MIN,sol = -1;
        for( int i = 0; i < nums.size(); ++i )
        {
            minn = min( minn, nums[i] );
            maxx = max( maxx, nums[i] );
        }
        // cout<<minn<<"  "<<maxx;
        for( int i = 0; i < nums.size(); ++i )
        {
            if( nums[i] != minn && nums[i] != maxx ) 
                {sol = nums[i];break;}
        }
        return sol;
        
        
    }
};