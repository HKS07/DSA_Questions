class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if( nums.size() == 1 ) return nums[0];
        int l = 0, n = nums.size(), h = n-1, sol = -1;
        
        while( l <= h )
        {
            int mid = (l+h)/2;
            if( mid == 0 )
            {
                if( nums[mid] != nums[mid+1] ) return nums[mid];
            }
            if( mid == n-1 )
            {
                if( nums[mid] != nums[mid-1] ) return nums[mid];
            }
            
            if(  nums[mid-1] != nums[mid] && nums[mid] != nums[mid+1] ) return nums[mid];
            //even
            if( mid%2 == 0 )
            {
                if( mid+1 <n && nums[mid] == nums[mid+1] )
                {
                    //left part is sorted
                    l = mid+1;
                }
                else
                {
                    h = mid;
                }
            }
            else
            {
                //odd
                if( mid-1>=0 && nums[mid] == nums[mid-1] )
                {
                    l = mid + 1;
                }
                else
                {
                    h = mid;
                }
            }
        }
        return -1;
    }
};