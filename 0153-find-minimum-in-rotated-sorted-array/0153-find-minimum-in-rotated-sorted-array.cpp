class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, n = nums.size(), high = n-1, mini = 5001;
        
        while( low <= high )
        {
            int mid = (low+high)/2;
            
            //left sorted
            if( nums[low] <= nums[mid] )
            {
                mini = min(mini,nums[low]);
                low = mid+1;
            }
            else
            {
                //right sorted
                mini = min(nums[mid],mini);
                high = mid-1;
            }
            // cout<<"low: "<<low<<" high: "<<high<<" mini: "<<mini<<endl;
        }
        return mini;
    }
};