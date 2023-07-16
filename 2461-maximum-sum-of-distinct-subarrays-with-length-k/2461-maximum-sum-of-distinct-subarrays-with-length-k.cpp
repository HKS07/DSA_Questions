class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        multiset<long long> s;
        long long i = 0, j = 0, sum = 0,sol = 0;;
        
        while( j < nums.size() && i <= j )
        {
            
            //unique element
            if( s.find(nums[j]) == s.end() )
            {
                s.insert(nums[j]);
                sum += nums[j];
            }
            else
            {
                while( nums[i] != nums[j] )
                {
                    s.erase( s.find(nums[i]) );
                    sum -= nums[i];
                    i++;
                }
                i++;
            }
            
            if( j - i + 1 < k )
            {
                ++j;
            }
            else if( j - i + 1 == k )
            {
                sol = max( sum, sol);
                s.erase( s.find(nums[i]) );
                sum -= nums[i];
                ++i; ++j;
            }
        }
        return sol;
    }
};