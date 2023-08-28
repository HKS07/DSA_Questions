class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        map<int,int> freq;
        for( auto i: nums)
            for( auto j: i )
                freq[j]++;

        vector<int> sol;

        for( auto i:freq )
        {
            if( i.second == nums.size() )
            {
                sol.push_back(i.first);
            }
        }
        return sol;
    }
};