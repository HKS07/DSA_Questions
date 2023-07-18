class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long sum = 0, i = 0, j = 0, score , sol = 0;
        
        while( j < nums.size() )
        {
            sum += nums[j];
            score = (j-i+1)*sum;
            
            while( score >= k && i <= j)
            {
                sum -=  nums[i];
                ++i;
                score = (j-i+1)*sum;
                
            }
            sol += (j-i+1);
            ++j;
        }
        return sol;
    }
};