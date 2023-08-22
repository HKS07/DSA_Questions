class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        map<int,int> mp;
        int totEle = 0;
        int len = 0;
        int l = 0, r = 0;
        
        while( r < nums.size() )
        {
            mp[nums[r]]++;
            totEle++;
            
            if( totEle - mp[nums[l]] <= k )
            {
                r++;
                len = max(mp[nums[l]],len);
            }
            else
            {
                while( totEle - mp[nums[l]] > k )
                {
                    //delete left element
                    mp[nums[l]]--;
                    if(mp[nums[l]] == 0 ) mp.erase(nums[l]);
                    totEle--;
                    l++;
                }
                len = max(len, mp[nums[l]]);
                ++r;
            }
        }
        for( auto m:mp )
        {
            len = max(len, m.second);
        }
        return len;
    }
};