class Solution {
public:
    vector<vector<int>> sol;
    void help( int idx, int targ, vector<int>& c, vector<int> temp)
    {
        if( idx == c.size() )
        {
            if( targ == 0 ) sol.push_back( temp );
            return;
        }
        
        if( c[idx] <= targ )
        {
            temp.push_back( c[idx] );
            help( idx, targ - c[idx], c, temp );
            temp.pop_back();
        }
        help( idx + 1, targ, c, temp );
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        help(0,target,candidates,{});
        return sol;
    }
};