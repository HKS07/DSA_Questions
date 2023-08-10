class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());
        
        int sol = 0;
        
        for( int i = 0; i < nums.size(); ++i )
        {
            if( s.find(nums[i]-1) == s.end() )
            {
                int count = 1;
                int n = nums[i];
                while( s.find(n+1) != s.end() )
                {
                    n = n + 1;
                    count++;
                }
                sol = max(sol,count);
            }
        }
        return sol;
    }
};