class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        set<int> marPos;
        
        for( int i = 0; i < nums.size(); ++i ) marPos.insert(nums[i]);
        
        for( int i = 0; i < moveFrom.size(); ++i )
        {
            // marbel exist at moveFrom Position
            if( marPos.find(moveFrom[i]) != marPos.end() )
            {
                marPos.erase(moveFrom[i]);
                marPos.insert(moveTo[i]);
            }
        }
        
        vector<int> sol;
        for(auto i:marPos) sol.push_back(i);
        return sol;
    }
};