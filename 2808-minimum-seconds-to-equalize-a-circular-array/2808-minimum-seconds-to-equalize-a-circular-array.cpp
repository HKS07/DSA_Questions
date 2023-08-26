class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        map<int,vector<int>> pos;
        for( int i = 0; i < nums.size(); ++i ) 
            pos[nums[i]].push_back(i);
        int n = nums.size();
        int time = n;
        
        for( auto it: pos )
        {
            int t = 0;
            
            for( int i = 1; i < it.second.size(); ++i )
            {
                t = max( t, (it.second[i] - it.second[i-1])/2);
            }
            int maxNow = max(t, (n-1 - it.second.back() + it.second[0] + 1)/2);
            time = min(time, maxNow);
        }
        return time;
    }
};