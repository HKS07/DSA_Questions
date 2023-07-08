class Solution {
public:
    void help( int idx, vector<int>& c, vector<vector<int>>& s, vector<int> t, int targ )
    {
        if( idx == c.size() )
        {
            if( targ == 0 ) s.push_back(t);
            return;
        }
        if( targ == 0 ) {s.push_back(t);
            return;}
        if( targ < 0 )  return;
        //take value at idx
        t.push_back(c[idx]);
        help(idx,c,s,t,targ-c[idx]);
        t.pop_back();
        help(idx+1,c,s,t,targ);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> t;
        help( 0, candidates, t, {}, target);
        return t;
    }
};