class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int t) {
     bool flag = false;
     int l=0,r=0,maxi=0;
        
        while( l < nums.size() && r <nums.size() )
        {
            if( !flag )
            {
                if( nums[l] %2==0 && nums[l]<=t )
                {
                    flag = true;
                    r=l+1;
                    maxi = max(maxi,1);
                }
                else l++;
            }
            else
            {
                if(nums[r]%2 != nums[r-1]%2 && nums[r] <=t )
                {
                    maxi = max( maxi, r-l+1);
                    r++;
                }
                else
                {
                    flag = false;
                    l = r;
                }
            }
        }
        return maxi;
    }
};