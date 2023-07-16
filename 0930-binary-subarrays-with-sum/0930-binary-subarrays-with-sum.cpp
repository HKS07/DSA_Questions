class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int i = 0, j = 0, sol = 0, sum = 0;
        map<int,int> freq;
        freq[sum] = 1;
        
        while( j < nums.size() )
        {
            sum += nums[j];
            int find = sum - goal;
            if( freq.find(find) != freq.end() )
            {
                sol += freq[find];
            }
            freq[sum]++;
            ++j;
        }
        return sol;
    }
};