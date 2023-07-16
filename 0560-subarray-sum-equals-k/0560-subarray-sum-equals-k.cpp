class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int i = 0, j = 0, sol = 0, sum = 0;
        map<int,int> mp;
        mp[sum] = 1;
        for( int i = 0; i < nums.size(); ++i )
        {
            sum += nums[i];
            int f = sum - k;
            if( mp.find(f) != mp.end())
            {
                
                sol += mp[f];
            }
            mp[sum]++;
        }
        
        
        return sol;
    }
};