class Solution {
public:
    vector<vector<int>> sol;
    void help( int idx, vector<int> &t )
    {
        if(idx == t.size() )
        {
            sol.push_back(t);
            return;
        }
        
        for(int pos = idx; pos < t.size(); ++pos )
        {
            swap(t[idx],t[pos] );
            help(idx+1,t);
            swap(t[idx],t[pos]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        help(0,nums);
        return sol;
    }
};