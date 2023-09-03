class Solution {
public:
    vector<vector<int>> sol;
    void help( int pos, vector<int> &n )
    {
        if( pos == n.size() ) 
        {
            sol.push_back(n);
            return;
        }
        
        for( int i = pos; i < n.size(); ++i )
        {
            swap(n[i],n[pos]);
            help(pos+1,n);
            swap(n[i],n[pos]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        help(0,nums);
        return sol;
    }
};